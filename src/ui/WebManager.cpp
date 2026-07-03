/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Web Manager
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#include "ui/WebManager.h"
#include "ui/HTMLPage.h"
#include <cstdio>

namespace PMS
{

/*==========================================================
    Constructor / Destructor
==========================================================*/

WebManager::WebManager() :
    _server(80),
    _state(nullptr),
    _ready(false)
{
}

WebManager::~WebManager()
{
    end();
}

/*==========================================================
    Service
==========================================================*/

bool WebManager::begin()
{
    if (_ready)
    {
        return true;
    }

    registerRoutes();

    _server.begin();

    _ready = true;

    return true;
}

void WebManager::update()
{
    if (!_ready)
    {
        return;
    }

    _server.handleClient();
}

void WebManager::end()
{
    if (!_ready)
    {
        return;
    }

    _server.stop();

    _ready = false;
}

bool WebManager::isReady() const
{
    return _ready;
}

/*==========================================================
    Runtime
==========================================================*/

void WebManager::setApplicationState(
    ApplicationState* state)
{
    _state = state;
}

/*==========================================================
    Route Registration
==========================================================*/

void WebManager::registerRoutes()
{
    _server.on(
        "/",
        HTTP_GET,
        [this]()
        {
            handleRoot();
        });

    _server.on(
        "/status",
        HTTP_GET,
        [this]()
        {
            handleStatus();
        });

    _server.onNotFound(
        [this]()
        {
            handleNotFound();
        });
}

/*==========================================================
    HTTP Handlers
==========================================================*/

void WebManager::handleRoot()
{
    _server.send_P(
        200,
        "text/html",
        INDEX_HTML);
}

void WebManager::handleStatus()
{
    if (_state == nullptr)
    {
        _server.send(
            503,
            "application/json",
            "{\"error\":\"ApplicationState unavailable\"}");

        return;
    }

    char timeBuffer[16];

    snprintf(
        timeBuffer,
        sizeof(timeBuffer),
        "%02u:%02u:%02u",
        _state->rtc.currentDateTime.hour,
        _state->rtc.currentDateTime.minute,
        _state->rtc.currentDateTime.second);

    const char* alarmState = "READY";

    switch (_state->alarm.state)
    {
        case AlarmState::Active:
            alarmState = "ALARM";
            break;

        case AlarmState::Acknowledged:
            alarmState = "ACK";
            break;

        default:
            break;
    }

    String json;

    json.reserve(256);

    json += "{";
    json += "\"machine\":\"";
    json += _state->configuration.machine.name;
    json += "\",";
    json += "\"time\":\"";
    json += timeBuffer;
    json += "\",";
    json += "\"alarm\":\"";
    json += alarmState;
    json += "\",";
    json += "\"rtcReady\":";
    json += (_state->system.rtcReady ? "true" : "false");
    json += "}";

    _server.send(
        200,
        "application/json",
        json);
}

void WebManager::handleNotFound()
{
    _server.send(
        404,
        "text/plain",
        "404 - Page Not Found");
}

} // namespace PMS
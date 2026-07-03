/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * WiFi Service
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#include "services/WiFiService.h"
#include <cstring>

namespace PMS
{

/*==========================================================
    Constructor / Destructor
==========================================================*/

WiFiService::WiFiService() :
    _ready(false),
    _running(false)
{
}

WiFiService::~WiFiService()
{
    end();
}

/*==========================================================
    Service
==========================================================*/

bool WiFiService::begin()
{
    if (_ready)
    {
        return true;
    }

    WiFi.mode(WIFI_AP);

    _ready = true;

    return true;
}

void WiFiService::update()
{
    // Reserved for future AP timeout handling
    // and connection monitoring.
}

void WiFiService::end()
{
    if (!_ready)
    {
        return;
    }

    stopAccessPoint();

    WiFi.mode(WIFI_OFF);

    _ready = false;
}

bool WiFiService::isReady() const
{
    return _ready;
}

/*==========================================================
    Access Point
==========================================================*/

bool WiFiService::startAccessPoint(
    const char* ssid,
    const char* password)
{
    if (!_ready)
    {
        return false;
    }

    bool result;

    if (password == nullptr || strlen(password) == 0)
    {
        result = WiFi.softAP(ssid);
    }
    else
    {
        result = WiFi.softAP(ssid, password);
    }

    _running = result;

    return result;
}

void WiFiService::stopAccessPoint()
{
    if (!_running)
    {
        return;
    }

    WiFi.softAPdisconnect(true);

    _running = false;
}

bool WiFiService::isAccessPointRunning() const
{
    return _running;
}

/*==========================================================
    Information
==========================================================*/

uint8_t WiFiService::connectedStations() const
{
    if (!_running)
    {
        return 0;
    }

    return static_cast<uint8_t>(WiFi.softAPgetStationNum());
}

IPAddress WiFiService::ipAddress() const
{
    return WiFi.softAPIP();
}

} // namespace PMS
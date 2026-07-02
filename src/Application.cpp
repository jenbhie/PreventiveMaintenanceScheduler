/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Application
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#include "Application.h"

namespace PMS
{

Application::Application()
{
}

bool Application::begin()
{
    //----------------------------------------------------------
    // Services
    //----------------------------------------------------------

    if (!_storage.begin())
    {
        return false;
    }

    if (!_rtc.begin())
    {
        return false;
    }

    if (!_gpio.begin())
    {
        return false;
    }

    if (!_wifi.begin())
    {
        return false;
    }

    //----------------------------------------------------------
    // Engines
    //----------------------------------------------------------

    if (!_scheduler.begin())
    {
        return false;
    }

    if (!_alarm.begin())
    {
        return false;
    }

    //----------------------------------------------------------
    // UI
    //----------------------------------------------------------

    if (!_display.begin())
    {
        return false;
    }

    _web.setApplicationState(&_state);

    if (!_web.begin())
    {
        return false;
    }

    //----------------------------------------------------------
    // Start Access Point
    //----------------------------------------------------------

    _wifi.startAccessPoint(
        _state.configuration.wifi.ssid,
        _state.configuration.wifi.password);

    //----------------------------------------------------------
    // System Ready
    //----------------------------------------------------------

    _state.system.initialized = true;

    return true;
}

void Application::update()
{
    //----------------------------------------------------------
    // Services
    //----------------------------------------------------------

    _storage.update();

    _rtc.update();

    _gpio.update();

    _wifi.update();

    //----------------------------------------------------------
    // Application
    //----------------------------------------------------------

    _scheduler.update();

    _scheduler.evaluate(_state);

    _alarm.update();

    _alarm.evaluate(_state);

    //----------------------------------------------------------
    // UI
    //----------------------------------------------------------

    _display.update();

    _display.showStatus(_state);

    _web.update();
}

} // namespace PMS
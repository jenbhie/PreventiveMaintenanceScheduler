/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Display Manager
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#include "ui/DisplayManager.h"

#include "../core/BuildInfo.h"
#include "../core/Constants.h"

namespace PMS
{

/*==========================================================
    Constructor / Destructor
==========================================================*/

DisplayManager::DisplayManager() :
    _lcd(
        Constants::LCD_ADDRESS,
        Constants::LCD_COLUMNS,
        Constants::LCD_ROWS),
    _ready(false),
    _lastRefresh(0)
{
}

DisplayManager::~DisplayManager()
{
    end();
}

/*==========================================================
    Service
==========================================================*/

bool DisplayManager::begin()
{
    if (_ready)
    {
        return true;
    }

    _lcd.init();

    _lcd.backlight();

    _lcd.clear();

    showBootScreen();

    _lastRefresh = millis();

    _ready = true;

    return true;
}

void DisplayManager::update()
{
    // Build001
    // Refreshing is performed by showStatus().
}

void DisplayManager::end()
{
    if (!_ready)
    {
        return;
    }

    _lcd.clear();

    _lcd.noBacklight();

    _ready = false;
}

bool DisplayManager::isReady() const
{
    return _ready;
}

/*==========================================================
    Boot Screen
==========================================================*/

void DisplayManager::showBootScreen()
{
    _lcd.clear();

    _lcd.setCursor(0, 0);
    _lcd.print("Preventive PM");

    _lcd.setCursor(0, 1);
    _lcd.print("Build ");
    _lcd.print(BuildInfo::BUILD_NUMBER);

    delay(1500);

    _lcd.clear();
}

/*==========================================================
    Status Screen
==========================================================*/

void DisplayManager::showStatus(
    const ApplicationState& state)
{
    if (!_ready)
    {
        return;
    }

    const uint32_t now = millis();

    if ((now - _lastRefresh) < Constants::DISPLAY_UPDATE_MS)
    {
        return;
    }

    _lastRefresh = now;

    //------------------------------------------------------
    // Line 1
    //------------------------------------------------------

    _lcd.setCursor(0, 0);

    _lcd.print("                ");

    _lcd.setCursor(0, 0);

    _lcd.print(state.configuration.machine.name);

    //------------------------------------------------------
    // Line 2
    //------------------------------------------------------

    char buffer[17];

    snprintf(
        buffer,
        sizeof(buffer),
        "%02u:%02u:%02u",
        state.rtc.currentDateTime.hour,
        state.rtc.currentDateTime.minute,
        state.rtc.currentDateTime.second);

    _lcd.setCursor(0, 1);

    _lcd.print("                ");

    _lcd.setCursor(0, 1);

    _lcd.print(buffer);

    _lcd.print(" ");

    switch (state.alarm.state)
    {
        case AlarmState::Idle:

            _lcd.print("READY");

            break;

        case AlarmState::Active:

            _lcd.print("ALARM");

            break;

        case AlarmState::Acknowledged:

            _lcd.print("ACK");

            break;

        default:

            _lcd.print("----");

            break;
    }
}

} // namespace PMS
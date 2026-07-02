/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * System Constants
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_CORE_CONSTANTS_H
#define PMS_CORE_CONSTANTS_H

#include <Arduino.h>

namespace PMS::Constants
{
    //=========================================================
    // Configuration
    //=========================================================

    inline constexpr uint16_t CONFIG_VERSION = 0x0100;

    //=========================================================
    // General
    //=========================================================

    inline constexpr uint16_t MAX_SCHEDULES = 50;

    inline constexpr uint16_t MACHINE_NAME_LENGTH = 32;

    inline constexpr uint16_t DESCRIPTION_LENGTH = 64;

    inline constexpr uint16_t WIFI_PASSWORD_LENGTH = 64;

    //=========================================================
    // LCD
    //=========================================================

    inline constexpr uint8_t LCD_COLUMNS = 16;

    inline constexpr uint8_t LCD_ROWS = 2;

    inline constexpr uint8_t LCD_ADDRESS = 0x27;

    //=========================================================
    // Task Update Periods
    //=========================================================

    inline constexpr uint32_t RTC_UPDATE_MS = 1000;

    inline constexpr uint32_t GPIO_UPDATE_MS = 20;

    inline constexpr uint32_t DISPLAY_UPDATE_MS = 250;

    inline constexpr uint32_t SCHEDULER_UPDATE_MS = 1000;

    inline constexpr uint32_t WIFI_UPDATE_MS = 1000;

    inline constexpr uint32_t WEB_UPDATE_MS = 50;

    inline constexpr uint32_t ALARM_UPDATE_MS = 20;

    //=========================================================
    // Buttons
    //=========================================================

    inline constexpr uint16_t BUTTON_DEBOUNCE_MS = 50;

    inline constexpr uint16_t LONG_PRESS_MS = 3000;

    //=========================================================
    // Alarm
    //=========================================================

    inline constexpr float DEFAULT_ON_TIME = 1.0f;

    inline constexpr float DEFAULT_OFF_TIME = 1.0f;

    inline constexpr float MIN_ON_TIME = 0.1f;

    inline constexpr float MAX_ON_TIME = 10.0f;

    inline constexpr float MIN_OFF_TIME = 0.1f;

    inline constexpr float MAX_OFF_TIME = 10.0f;

    //=========================================================
    // WiFi
    //=========================================================

    inline constexpr uint16_t DEFAULT_AP_TIMEOUT_MIN = 15;

    inline constexpr uint16_t MAX_AP_TIMEOUT_MIN = 240;

    //=========================================================
    // Preferences
    //=========================================================

    inline constexpr char PREFERENCES_NAMESPACE[] = "PMS";

    inline constexpr char DATABASE_KEY[] = "database";
}

#endif
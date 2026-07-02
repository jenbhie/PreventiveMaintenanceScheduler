/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Constants
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_CONSTANTS_H
#define PMS_CONSTANTS_H

#include <Arduino.h>

namespace Constants
{
    //======================================================================
    // Firmware
    //======================================================================

    inline constexpr uint16_t CONFIG_VERSION = 0x0100;

    //======================================================================
    // Timing (milliseconds)
    //======================================================================

    inline constexpr uint32_t RTC_UPDATE_INTERVAL_MS        = 1000;
    inline constexpr uint32_t GPIO_UPDATE_INTERVAL_MS       = 20;
    inline constexpr uint32_t DISPLAY_UPDATE_INTERVAL_MS    = 250;
    inline constexpr uint32_t SCHEDULER_UPDATE_INTERVAL_MS  = 1000;
    inline constexpr uint32_t ALARM_UPDATE_INTERVAL_MS      = 20;
    inline constexpr uint32_t WIFI_UPDATE_INTERVAL_MS       = 1000;
    inline constexpr uint32_t WEB_UPDATE_INTERVAL_MS        = 10;
    inline constexpr uint32_t DASHBOARD_REFRESH_MS          = 1000;

    //======================================================================
    // Button Timing
    //======================================================================

    inline constexpr uint16_t BUTTON_DEBOUNCE_MS            = 50;
    inline constexpr uint16_t BUTTON_LONG_PRESS_MS          = 3000;

    //======================================================================
    // LCD
    //======================================================================

    inline constexpr uint8_t LCD_COLUMNS                    = 16;
    inline constexpr uint8_t LCD_ROWS                       = 2;
    inline constexpr uint8_t LCD_I2C_ADDRESS                = 0x27;

    //======================================================================
    // Web Server
    //======================================================================

    inline constexpr uint16_t WEB_SERVER_PORT               = 80;

    //======================================================================
    // WiFi
    //======================================================================

    inline constexpr uint16_t DEFAULT_AP_TIMEOUT_MINUTES    = 15;
    inline constexpr uint16_t MIN_AP_TIMEOUT_MINUTES        = 0;
    inline constexpr uint16_t MAX_AP_TIMEOUT_MINUTES        = 240;

    //======================================================================
    // Alarm
    //======================================================================

    inline constexpr float DEFAULT_ALARM_ON_SECONDS         = 1.0F;
    inline constexpr float DEFAULT_ALARM_OFF_SECONDS        = 1.0F;

    inline constexpr float MIN_ALARM_SECONDS                = 0.10F;
    inline constexpr float MAX_ALARM_SECONDS                = 10.00F;

    //======================================================================
    // Schedule
    //======================================================================

    inline constexpr uint16_t MAX_SCHEDULES                = 50;

    //======================================================================
    // Machine
    //======================================================================

    inline constexpr uint8_t MACHINE_NAME_MIN_LENGTH        = 3;
    inline constexpr uint8_t MACHINE_NAME_MAX_LENGTH        = 20;

    inline constexpr uint8_t WIFI_PASSWORD_MAX_LENGTH       = 63;

    //======================================================================
    // Preferences
    //======================================================================

    inline constexpr char PREFERENCES_NAMESPACE[]           = "PMS";

    inline constexpr char KEY_CONFIGURATION[]               = "cfg";
    inline constexpr char KEY_SCHEDULES[]                   = "sch";
    inline constexpr char KEY_PREVIOUS_PM[]                 = "ppm";
}

#endif
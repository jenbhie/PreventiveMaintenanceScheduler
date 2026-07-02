/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Build Information
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_BUILD_INFO_H
#define PMS_BUILD_INFO_H

#include <Arduino.h>

namespace BuildInfo
{
    //=========================================================
    // Project
    //=========================================================

    inline constexpr char PROJECT_NAME[] =
        "Preventive Maintenance Scheduler";

    inline constexpr char PROJECT_SHORT_NAME[] =
        "PMS";

    inline constexpr char AUTHOR[] =
        "Jenerwin Camba";

    inline constexpr char COPYRIGHT[] =
        "Designed and created by Jenerwin Camba";

    //=========================================================
    // Version
    //=========================================================

    inline constexpr uint8_t VERSION_MAJOR = 1;

    inline constexpr uint8_t VERSION_MINOR = 0;

    inline constexpr uint16_t BUILD = 1;

    inline constexpr char VERSION_STRING[] =
        "1.0.001";

    //=========================================================
    // Hardware
    //=========================================================

    inline constexpr char TARGET_BOARD[] =
        "Arduino Nano ESP32";

    inline constexpr char FRAMEWORK[] =
        "Arduino";

    inline constexpr char RTC[] =
        "DS3231";

    inline constexpr char DISPLAY[] =
        "16x2 I2C LCD";

    //=========================================================
    // Build
    //=========================================================

    inline constexpr char BUILD_DATE[] =
        __DATE__;

    inline constexpr char BUILD_TIME[] =
        __TIME__;
}

#endif
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

#ifndef PMS_CORE_BUILDINFO_H
#define PMS_CORE_BUILDINFO_H

#include <Arduino.h>

namespace PMS::BuildInfo
{
    //==============================================================
    // Project
    //==============================================================

    inline constexpr char PROJECT_NAME[] =
        "Preventive Maintenance Scheduler";

    inline constexpr char PROJECT_CODE[] =
        "PMS";

    inline constexpr char AUTHOR[] =
        "Jenerwin Camba";

    inline constexpr char VERSION[] =
        "1.0.0";

    inline constexpr uint16_t BUILD_NUMBER = 1;

    //==============================================================
    // Target Hardware
    //==============================================================

    inline constexpr char BOARD[] =
        "Arduino Nano ESP32";

    inline constexpr char MCU[] =
        "ESP32-S3";

    inline constexpr char FRAMEWORK[] =
        "Arduino";

    inline constexpr char RTC[] =
        "DS3231";

    inline constexpr char DISPLAY[] =
        "16x2 I2C LCD";

    //==============================================================
    // Compiler Information
    //==============================================================

    inline constexpr char BUILD_DATE[] = __DATE__;

    inline constexpr char BUILD_TIME[] = __TIME__;
}

#endif // PMS_CORE_BUILDINFO_H
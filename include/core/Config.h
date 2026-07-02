/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * System Configuration
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_CORE_CONFIG_H
#define PMS_CORE_CONFIG_H

#include <Arduino.h>

#include "BuildInfo.h"
#include "Constants.h"
#include "Pins.h"
#include "Types.h"

namespace PMS
{

//==========================================================
// Machine
//==========================================================

struct MachineConfig
{
    char name[Constants::MACHINE_NAME_LENGTH];

    TimeFormat timeFormat;

    bool wifiPasswordEnabled;
};

//==========================================================
// WiFi
//==========================================================

struct WiFiConfig
{
    char ssid[32];

    char password[Constants::WIFI_PASSWORD_LENGTH];

    uint16_t accessPointTimeoutMinutes;
};

//==========================================================
// Alarm
//==========================================================

struct AlarmConfig
{
    float onTimeSeconds;

    float offTimeSeconds;
};

//==========================================================
// GPIO
//==========================================================

struct GPIOConfig
{
    OutputPin pmOutput;

    OutputPin eeOutput;

    OutputPin otherOutput;

    OutputPin commonOutput;

    OutputPin alarmOutput;

    uint8_t resetButton;

    uint8_t wifiButton;
};

//==========================================================
// Configuration Header
//==========================================================

struct ConfigurationHeader
{
    uint16_t version;

    uint16_t size;
};

//==========================================================
// Complete System Configuration
//==========================================================

struct SystemConfig
{
    ConfigurationHeader header;

    MachineConfig machine;

    WiFiConfig wifi;

    AlarmConfig alarm;

    GPIOConfig gpio;
};

//==========================================================
// Factory Defaults
//==========================================================

namespace Factory
{
    inline constexpr char MACHINE_NAME[] = "PMS-001";

    inline constexpr char AP_SSID[] = "PreventiveMaintenanceScheduler";

    inline constexpr char AP_PASSWORD[] = "";

    inline constexpr MachineConfig MACHINE =
    {
        "PMS-001",
        TimeFormat::Hour24,
        false
    };

    inline constexpr WiFiConfig WIFI =
    {
        "PreventiveMaintenanceScheduler",
        "",
        Constants::DEFAULT_AP_TIMEOUT_MIN
    };

    inline constexpr AlarmConfig ALARM =
    {
        Constants::DEFAULT_ON_TIME,
        Constants::DEFAULT_OFF_TIME
    };

    inline constexpr GPIOConfig GPIO =
    {
        { Pins::PM_OUTPUT,     OutputMode::ActiveHigh },
        { Pins::EE_OUTPUT,     OutputMode::ActiveHigh },
        { Pins::OTHER_OUTPUT,  OutputMode::ActiveHigh },
        { Pins::COMMON_OUTPUT, OutputMode::ActiveHigh },
        { Pins::ALARM_OUTPUT,  OutputMode::ActiveHigh },

        Pins::RESET_BUTTON,
        Pins::WIFI_BUTTON
    };

    inline constexpr ConfigurationHeader HEADER =
    {
        Constants::CONFIG_VERSION,
        sizeof(SystemConfig)
    };
}

} // namespace PMS

#endif
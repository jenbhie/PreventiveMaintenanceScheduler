/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Configuration Defaults
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_CONFIG_H
#define PMS_CONFIG_H

#include <Arduino.h>

#include "BuildInfo.h"
#include "Constants.h"
#include "Pins.h"
#include "Types.h"

namespace PMS::Config
{

//======================================================================
// Machine
//======================================================================

inline constexpr char DEFAULT_MACHINE_NAME[] =
    "PMS-001";

//======================================================================
// WiFi
//======================================================================

inline constexpr char DEFAULT_AP_SSID[] =
    "PreventiveMaintenanceScheduler";

inline constexpr char DEFAULT_AP_PASSWORD[] =
    "";

inline constexpr bool DEFAULT_AP_PASSWORD_ENABLED =
    false;

//======================================================================
// Display
//======================================================================

inline constexpr TimeFormat DEFAULT_TIME_FORMAT =
    TimeFormat::Hour24;

//======================================================================
// Outputs
//======================================================================

inline constexpr OutputMode DEFAULT_OUTPUT_MODE =
    OutputMode::ActiveHigh;

//======================================================================
// GPIO Factory Assignment
//
// NOTE:
// Pin assignments are configurable from the Settings page.
// These values are only used during the first boot or after
// a factory reset.
//======================================================================

inline constexpr GPIOConfiguration DEFAULT_GPIO =
{
    // PM Output
    {
        Pins::PM_OUTPUT,
        DEFAULT_OUTPUT_MODE
    },

    // EE Output
    {
        Pins::EE_OUTPUT,
        DEFAULT_OUTPUT_MODE
    },

    // Other Output
    {
        Pins::OTHER_OUTPUT,
        DEFAULT_OUTPUT_MODE
    },

    // Common Output
    {
        Pins::COMMON_OUTPUT,
        DEFAULT_OUTPUT_MODE
    },

    // Alarm / Buzzer Output
    {
        Pins::ALARM_OUTPUT,
        DEFAULT_OUTPUT_MODE
    },

    // Alarm Reset Button
    Pins::RESET_BUTTON,

    // WiFi Wake Button
    Pins::WIFI_BUTTON
};

//======================================================================
// Alarm
//======================================================================

inline constexpr AlarmConfig DEFAULT_ALARM =
{
    Constants::DEFAULT_ALARM_ON_SECONDS,
    Constants::DEFAULT_ALARM_OFF_SECONDS
};

//======================================================================
// WiFi
//======================================================================

inline constexpr WiFiConfig DEFAULT_WIFI =
{
    Constants::DEFAULT_AP_TIMEOUT_MINUTES
};

//======================================================================
// Machine
//======================================================================

inline constexpr MachineConfig DEFAULT_MACHINE =
{
    DEFAULT_MACHINE_NAME,

    DEFAULT_AP_PASSWORD,

    DEFAULT_AP_PASSWORD_ENABLED,

    DEFAULT_TIME_FORMAT
};

//======================================================================
// System Configuration Header
//======================================================================

inline constexpr ConfigurationHeader DEFAULT_HEADER =
{
    Constants::CONFIG_VERSION,

    sizeof(SystemConfig)
};

} // namespace PMS::Config

#endif
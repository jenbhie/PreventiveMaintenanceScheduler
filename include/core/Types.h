/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Common Data Types
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_TYPES_H
#define PMS_TYPES_H

#include <Arduino.h>

namespace PMS
{

//======================================================================
// Enumerations
//======================================================================

enum class ActivityType : uint8_t
{
    PM = 0,
    EE,
    Other
};

enum class ScheduleStatus : uint8_t
{
    Pending = 0,
    Active,
    Completed,
    Cancelled
};

enum class AlarmState : uint8_t
{
    Idle = 0,
    Active,
    Acknowledged
};

enum class OutputMode : uint8_t
{
    ActiveHigh = 0,
    ActiveLow
};

enum class TimeFormat : uint8_t
{
    Hour24 = 0,
    Hour12
};

enum class WiFiMode : uint8_t
{
    Disabled = 0,
    AccessPoint
};

//======================================================================
// RTC
//======================================================================

struct DateTime
{
    uint16_t year;
    uint8_t month;
    uint8_t day;

    uint8_t hour;
    uint8_t minute;
    uint8_t second;

    uint8_t dayOfWeek;
};

//======================================================================
// GPIO
//======================================================================

struct GPIOPin
{
    uint8_t pin;
    OutputMode mode;
};

//======================================================================
// Machine
//======================================================================

struct MachineConfig
{
    char machineName[21];

    char wifiPassword[64];

    bool passwordEnabled;

    TimeFormat timeFormat;
};

//======================================================================
// WiFi
//======================================================================

struct WiFiConfig
{
    uint16_t apTimeoutMinutes;
};

//======================================================================
// Alarm
//======================================================================

struct AlarmConfig
{
    float onSeconds;

    float offSeconds;
};

//======================================================================
// GPIO Configuration
//======================================================================

struct GPIOConfiguration
{
    GPIOPin pmOutput;

    GPIOPin eeOutput;

    GPIOPin otherOutput;

    GPIOPin commonOutput;

    GPIOPin buzzerOutput;

    uint8_t resetButton;

    uint8_t wifiButton;
};

//======================================================================
// Schedule
//======================================================================

struct Schedule
{
    uint16_t id;

    ActivityType activity;

    DateTime trigger;

    ScheduleStatus status;

    char description[64];
};

//======================================================================
// Previous PM
//======================================================================

struct PreviousPM
{
    bool valid;

    DateTime completed;
};

//======================================================================
// Configuration Header
//======================================================================

struct ConfigurationHeader
{
    uint16_t version;

    uint16_t size;
};

//======================================================================
// System Configuration
//======================================================================

struct SystemConfig
{
    ConfigurationHeader header;

    MachineConfig machine;

    WiFiConfig wifi;

    AlarmConfig alarm;

    GPIOConfiguration gpio;
};

} // namespace PMS

#endif
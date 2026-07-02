/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Common Types
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_CORE_TYPES_H
#define PMS_CORE_TYPES_H

#include <Arduino.h>

namespace PMS
{

//==========================================================
// Enumerations
//==========================================================

enum class ActivityType : uint8_t
{
    PM = 0,
    EE,
    OTHER
};

enum class ScheduleState : uint8_t
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

//==========================================================
// Date & Time
//==========================================================

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

//==========================================================
// Output Pin
//==========================================================

struct OutputPin
{
    uint8_t pin;

    OutputMode mode;
};

//==========================================================
// Schedule
//==========================================================

struct Schedule
{
    uint16_t id;

    ActivityType activity;

    DateTime trigger;

    ScheduleState state;

    char description[64];
};

//==========================================================
// Previous PM
//==========================================================

struct PreviousPM
{
    bool valid;

    DateTime completed;
};

} // namespace PMS

#endif
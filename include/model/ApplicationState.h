/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Application Runtime State
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_APPLICATION_STATE_H
#define PMS_APPLICATION_STATE_H

#include "../core/Types.h"

namespace PMS
{

//======================================================================
// Runtime State
//======================================================================

struct RTCState
{
    DateTime currentTime;

    bool synchronized = false;

    bool rtcPresent = false;
};

struct AlarmRuntime
{
    AlarmState state = AlarmState::Idle;

    bool outputActive = false;

    bool buzzerActive = false;

    uint32_t lastToggle = 0;
};

struct WiFiRuntime
{
    bool accessPointRunning = false;

    bool clientConnected = false;

    uint8_t connectedClients = 0;

    uint32_t startedAt = 0;
};

struct SchedulerRuntime
{
    Schedule schedules[Constants::MAX_SCHEDULES];

    uint16_t scheduleCount = 0;

    int16_t remainingDays = 0;

    bool overdue = false;
};

struct DashboardRuntime
{
    PreviousPM previousPM;

    Schedule nextPM;

    Schedule nextEE;

    Schedule nextOther;
};

struct SystemRuntime
{
    bool initialized = false;

    bool configurationLoaded = false;

    bool alarmEnabled = true;

    bool rebootRequested = false;

    bool factoryResetRequested = false;
};

//======================================================================
// Complete Runtime State
//======================================================================

struct ApplicationState
{
    SystemConfig configuration;

    RTCState rtc;

    SchedulerRuntime scheduler;

    AlarmRuntime alarm;

    WiFiRuntime wifi;

    DashboardRuntime dashboard;

    SystemRuntime system;
};

} // namespace PMS

#endif
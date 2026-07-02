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

#ifndef PMS_MODEL_APPLICATION_STATE_H
#define PMS_MODEL_APPLICATION_STATE_H

#include "../core/Config.h"

namespace PMS
{

//==========================================================
// RTC Runtime
//==========================================================

struct RTCState
{
    DateTime currentDateTime {};

    bool present = false;

    bool synchronized = false;
};

//==========================================================
// Scheduler Runtime
//==========================================================

struct SchedulerState
{
    Schedule schedules[Constants::MAX_SCHEDULES];

    uint16_t count = 0;

    PreviousPM previousPM {};

    int16_t remainingDays = 0;

    bool overdue = false;
};

//==========================================================
// Alarm Runtime
//==========================================================

struct AlarmRuntime
{
    AlarmState state = AlarmState::Idle;

    bool outputState = false;

    bool acknowledged = false;

    uint32_t lastToggle = 0;
};

//==========================================================
// WiFi Runtime
//==========================================================

struct WiFiRuntime
{
    bool accessPointEnabled = false;

    bool clientConnected = false;

    uint8_t connectedClients = 0;

    uint32_t startTime = 0;
};

//==========================================================
// System Runtime
//==========================================================

struct SystemRuntime
{
    bool initialized = false;

    bool configurationLoaded = false;

    bool rtcReady = false;

    bool storageReady = false;

    bool rebootRequested = false;

    bool factoryResetRequested = false;
};

//==========================================================
// Dashboard Runtime
//==========================================================

struct DashboardRuntime
{
    Schedule nextPM {};

    Schedule nextEE {};

    Schedule nextOther {};
};

//==========================================================
// Complete Application State
//==========================================================

struct ApplicationState
{
    //------------------------------------------------------
    // Persistent Configuration
    //------------------------------------------------------

    SystemConfig configuration {};

    //------------------------------------------------------
    // Runtime
    //------------------------------------------------------

    RTCState rtc {};

    SchedulerState scheduler {};

    AlarmRuntime alarm {};

    WiFiRuntime wifi {};

    DashboardRuntime dashboard {};

    SystemRuntime system {};
};

} // namespace PMS

#endif
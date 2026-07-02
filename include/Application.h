/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Application
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_APPLICATION_H
#define PMS_APPLICATION_H

#include <Arduino.h>

#include "model/ApplicationState.h"

#include "services/StorageService.h"
#include "services/RTCService.h"
#include "services/GPIOService.h"
#include "services/WiFiService.h"

#include "application/SchedulerEngine.h"
#include "application/AlarmEngine.h"

#include "ui/DisplayManager.h"
#include "ui/WebManager.h"

namespace PMS
{

class Application
{
public:

    Application();

    bool begin();

    void update();

private:

    //----------------------------------------------------------
    // Shared Runtime State
    //----------------------------------------------------------

    ApplicationState _state;

    //----------------------------------------------------------
    // Services
    //----------------------------------------------------------

    StorageService _storage;

    RTCService _rtc;

    GPIOService _gpio;

    WiFiService _wifi;

    //----------------------------------------------------------
    // Application
    //----------------------------------------------------------

    SchedulerEngine _scheduler;

    AlarmEngine _alarm;

    //----------------------------------------------------------
    // UI
    //----------------------------------------------------------

    DisplayManager _display;

    WebManager _web;
};

}

#endif
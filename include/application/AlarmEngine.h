/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Alarm Engine
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_APPLICATION_ALARM_ENGINE_H
#define PMS_APPLICATION_ALARM_ENGINE_H

#include <Arduino.h>

#include "../model/ApplicationState.h"

namespace PMS
{

class AlarmEngine
{
public:

    AlarmEngine();
    ~AlarmEngine();

    //----------------------------------------------------------
    // Engine
    //----------------------------------------------------------

    bool begin();

    void update();

    void end();

    //----------------------------------------------------------
    // Alarm
    //----------------------------------------------------------

    void evaluate(ApplicationState& state);

private:

    bool _ready;

    void updateAlarmState(
        ApplicationState& state);

    void updateOutputs(
        ApplicationState& state);
};

}

#endif
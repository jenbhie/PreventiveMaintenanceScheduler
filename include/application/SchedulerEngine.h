/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Scheduler Engine
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_APPLICATION_SCHEDULER_ENGINE_H
#define PMS_APPLICATION_SCHEDULER_ENGINE_H

#include <Arduino.h>

#include "../model/ApplicationState.h"

namespace PMS
{

class SchedulerEngine
{
public:

    SchedulerEngine();

    ~SchedulerEngine();

    //----------------------------------------------------------
    // Engine
    //----------------------------------------------------------

    bool begin();

    void update();

    void end();

    //----------------------------------------------------------
    // Runtime
    //----------------------------------------------------------

    void evaluate(ApplicationState& state);

private:

    bool _ready;

    void updateNextSchedules(
        ApplicationState& state);

    void updateRemainingDays(
        ApplicationState& state);

    void updateOverdueStatus(
        ApplicationState& state);
};

}

#endif
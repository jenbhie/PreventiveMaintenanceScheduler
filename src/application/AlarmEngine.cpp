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

#include "application/AlarmEngine.h"

namespace PMS
{

/*==========================================================
    Constructor / Destructor
==========================================================*/

AlarmEngine::AlarmEngine() :
    _ready(false)
{
}

AlarmEngine::~AlarmEngine()
{
    end();
}

/*==========================================================
    Engine
==========================================================*/

bool AlarmEngine::begin()
{
    if (_ready)
    {
        return true;
    }

    _ready = true;

    return true;
}

void AlarmEngine::update()
{
    // Reserved for future alarm timing logic.
}

void AlarmEngine::end()
{
    _ready = false;
}

/*==========================================================
    Evaluation
==========================================================*/

void AlarmEngine::evaluate(
    ApplicationState& state)
{
    if (!_ready)
    {
        return;
    }

    updateAlarmState(state);

    updateOutputs(state);
}

/*==========================================================
    Alarm State
==========================================================*/

void AlarmEngine::updateAlarmState(
    ApplicationState& state)
{
    // Build001
    //
    // Alarm becomes active whenever the scheduler
    // reports an overdue condition.

    if (state.scheduler.overdue)
    {
        if (state.alarm.state == AlarmState::Idle)
        {
            state.alarm.state = AlarmState::Active;
        }
    }
    else
    {
        state.alarm.state = AlarmState::Idle;
    }
}

/*==========================================================
    Outputs
==========================================================*/

void AlarmEngine::updateOutputs(
    ApplicationState& state)
{
    switch (state.alarm.state)
    {
        case AlarmState::Idle:

            state.alarm.outputState = false;

            break;

        case AlarmState::Active:

            state.alarm.outputState = true;

            break;

        case AlarmState::Acknowledged:

            state.alarm.outputState = false;

            break;

        default:

            state.alarm.outputState = false;

            break;
    }
}

} // namespace PMS
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

#include "application/SchedulerEngine.h"

namespace PMS
{

/*==========================================================
    Constructor / Destructor
==========================================================*/

SchedulerEngine::SchedulerEngine() :
    _ready(false)
{
}

SchedulerEngine::~SchedulerEngine()
{
    end();
}

/*==========================================================
    Engine
==========================================================*/

bool SchedulerEngine::begin()
{
    if (_ready)
    {
        return true;
    }

    _ready = true;

    return true;
}

void SchedulerEngine::update()
{
    // Reserved for future scheduler tasks.
}

void SchedulerEngine::end()
{
    _ready = false;
}

/*==========================================================
    Evaluation
==========================================================*/

void SchedulerEngine::evaluate(
    ApplicationState& state)
{
    if (!_ready)
    {
        return;
    }

    updateNextSchedules(state);

    updateRemainingDays(state);

    updateOverdueStatus(state);
}

/*==========================================================
    Next Schedule Evaluation
==========================================================*/

void SchedulerEngine::updateNextSchedules(
    ApplicationState& state)
{
    bool pmFound = false;
    bool eeFound = false;
    bool otherFound = false;

    for (uint16_t i = 0; i < state.scheduler.count; i++)
    {
        const Schedule& schedule =
            state.scheduler.schedules[i];

        if (schedule.state != ScheduleState::Pending)
        {
            continue;
        }

        switch (schedule.activity)
        {
            case ActivityType::PM:

                if (!pmFound)
                {
                    state.dashboard.nextPM = schedule;
                    pmFound = true;
                }

                break;

            case ActivityType::EE:

                if (!eeFound)
                {
                    state.dashboard.nextEE = schedule;
                    eeFound = true;
                }

                break;

            case ActivityType::OTHER:

                if (!otherFound)
                {
                    state.dashboard.nextOther = schedule;
                    otherFound = true;
                }

                break;

            default:
                break;
        }
    }
}

/*==========================================================
    Remaining Days
==========================================================*/

void SchedulerEngine::updateRemainingDays(
    ApplicationState& state)
{
    // Build001
    //
    // Date difference calculation will be introduced
    // in Build002 after the DateTime utility library
    // is added.
    //
    // For now, initialize the runtime value.

    state.scheduler.remainingDays = 0;
}

/*==========================================================
    Overdue Status
==========================================================*/

void SchedulerEngine::updateOverdueStatus(
    ApplicationState& state)
{
    // Build001
    //
    // Overdue detection depends on accurate date
    // comparison. This will also be implemented in
    // Build002 together with the DateTime utilities.

    state.scheduler.overdue = false;
}

} // namespace PMS
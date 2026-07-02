/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Storage Service
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_STORAGE_SERVICE_H
#define PMS_STORAGE_SERVICE_H

#include <Arduino.h>
#include <Preferences.h>

#include "../core/Types.h"

namespace PMS
{

class StorageService
{
public:

    StorageService();

    bool begin();

    void end();

    bool isReady() const;

    bool loadConfiguration(SystemConfig& configuration);

    bool saveConfiguration(
        const SystemConfig& configuration);

    bool loadPreviousPM(
        PreviousPM& previousPM);

    bool savePreviousPM(
        const PreviousPM& previousPM);

    bool loadSchedules(
        Schedule schedules[],
        uint16_t& count);

    bool saveSchedules(
        const Schedule schedules[],
        uint16_t count);

    bool clearSchedules();

    bool factoryReset();

private:

    Preferences _preferences;

    bool _ready;

    struct PersistentData
    {
        SystemConfig configuration;

        PreviousPM previousPM;

        uint16_t scheduleCount;

        Schedule schedules[Constants::MAX_SCHEDULES];
    };

    bool readDatabase(
        PersistentData& database);

    bool writeDatabase(
        const PersistentData& database);

    void createFactoryConfiguration(
        SystemConfig& configuration);

    bool validateConfiguration(
        const SystemConfig& configuration) const;
};

}

#endif
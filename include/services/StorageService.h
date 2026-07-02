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

#ifndef PMS_SERVICES_STORAGE_SERVICE_H
#define PMS_SERVICES_STORAGE_SERVICE_H

#include <Arduino.h>
#include <Preferences.h>

#include "../core/Config.h"

namespace PMS
{

class StorageService
{
public:

    StorageService();
    ~StorageService();

    //----------------------------------------------------------
    // Service
    //----------------------------------------------------------

    bool begin();
    void update();
    void end();

    bool isReady() const;

    //----------------------------------------------------------
    // Configuration
    //----------------------------------------------------------

    bool loadConfiguration(SystemConfig& config);

    bool saveConfiguration(const SystemConfig& config);

    //----------------------------------------------------------
    // Previous PM
    //----------------------------------------------------------

    bool loadPreviousPM(PreviousPM& previousPM);

    bool savePreviousPM(const PreviousPM& previousPM);

    //----------------------------------------------------------
    // Schedule Database
    //----------------------------------------------------------

    bool loadSchedules(
        Schedule schedules[],
        uint16_t& count);

    bool saveSchedules(
        const Schedule schedules[],
        uint16_t count);

    bool clearSchedules();

    //----------------------------------------------------------
    // Maintenance
    //----------------------------------------------------------

    bool factoryReset();

private:

    //----------------------------------------------------------
    // Database Structures
    //----------------------------------------------------------

    struct DatabaseHeader
    {
        uint16_t version;
        uint16_t size;
        uint32_t crc;
    };

    struct PersistentDatabase
    {
        DatabaseHeader header;

        SystemConfig configuration;

        PreviousPM previousPM;

        uint16_t scheduleCount;

        Schedule schedules[Constants::MAX_SCHEDULES];
    };

    //----------------------------------------------------------
    // Members
    //----------------------------------------------------------

    Preferences _preferences;

    bool _ready;

    bool _dirty;

    PersistentDatabase _database;

    //----------------------------------------------------------
    // Internal Helpers
    //----------------------------------------------------------

    bool readDatabase();

    bool writeDatabase();

    void initializeDatabase();

    void createFactoryConfiguration(
        SystemConfig& config);

    bool validateConfiguration(
        const SystemConfig& config) const;
};

}

#endif
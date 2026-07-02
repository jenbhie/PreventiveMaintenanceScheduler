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

#include "services/StorageService.h"

#include <cstring>

namespace PMS
{

namespace
{
    constexpr char DATABASE_KEY[] = "database";
}

/*==========================================================
    Constructor / Destructor
==========================================================*/

StorageService::StorageService() :
    _ready(false),
    _dirty(false)
{
    std::memset(&_database, 0, sizeof(_database));
}

StorageService::~StorageService()
{
    end();
}

/*==========================================================
    Initialization
==========================================================*/

bool StorageService::begin()
{
    if (_ready)
    {
        return true;
    }

    if (!_preferences.begin(Constants::PREFERENCES_NAMESPACE, false))
    {
        return false;
    }

    _ready = true;

    if (!readDatabase())
    {
        initializeDatabase();

        if (!writeDatabase())
        {
            return false;
        }
    }

    return true;
}

void StorageService::update()
{
    if (!_ready)
    {
        return;
    }

    if (!_dirty)
    {
        return;
    }

    if (writeDatabase())
    {
        _dirty = false;
    }
}

void StorageService::end()
{
    if (!_ready)
    {
        return;
    }

    update();

    _preferences.end();

    _ready = false;
}

bool StorageService::isReady() const
{
    return _ready;
}

/*==========================================================
    Database
==========================================================*/

bool StorageService::readDatabase()
{
    const size_t expectedSize = sizeof(PersistentDatabase);

    if (_preferences.getBytesLength(DATABASE_KEY) != expectedSize)
    {
        return false;
    }

    const size_t bytes =
        _preferences.getBytes(
            DATABASE_KEY,
            &_database,
            expectedSize);

    if (bytes != expectedSize)
    {
        return false;
    }

    if (_database.header.version != Constants::CONFIG_VERSION)
    {
        return false;
    }

    if (_database.header.size != expectedSize)
    {
        return false;
    }

    if (!validateConfiguration(_database.configuration))
    {
        return false;
    }

    if (_database.scheduleCount > Constants::MAX_SCHEDULES)
    {
        return false;
    }

    return true;
}

bool StorageService::writeDatabase()
{
    _database.header.version = Constants::CONFIG_VERSION;
    _database.header.size = sizeof(PersistentDatabase);

    // Reserved for future CRC implementation.
    _database.header.crc = 0;

    const size_t bytes =
        _preferences.putBytes(
            DATABASE_KEY,
            &_database,
            sizeof(PersistentDatabase));

    return (bytes == sizeof(PersistentDatabase));
}

void StorageService::initializeDatabase()
{
    std::memset(
        &_database,
        0,
        sizeof(_database));

    _database.header.version =
        Constants::CONFIG_VERSION;

    _database.header.size =
        sizeof(PersistentDatabase);

    _database.header.crc = 0;

    createFactoryConfiguration(
        _database.configuration);

    _database.previousPM.valid = false;

    _database.scheduleCount = 0;

    _dirty = false;
}

/*==========================================================
    Configuration
==========================================================*/

bool StorageService::loadConfiguration(
    SystemConfig& config)
{
    if (!_ready)
    {
        return false;
    }

    config = _database.configuration;

    return true;
}

bool StorageService::saveConfiguration(
    const SystemConfig& config)
{
    if (!_ready)
    {
        return false;
    }

    if (!validateConfiguration(config))
    {
        return false;
    }

    _database.configuration = config;

    _dirty = true;

    return true;
}

/*==========================================================
    Previous PM
==========================================================*/

bool StorageService::loadPreviousPM(
    PreviousPM& previousPM)
{
    if (!_ready)
    {
        return false;
    }

    previousPM = _database.previousPM;

    return true;
}

bool StorageService::savePreviousPM(
    const PreviousPM& previousPM)
{
    if (!_ready)
    {
        return false;
    }

    _database.previousPM = previousPM;

    _dirty = true;

    return true;
}

/*==========================================================
    Schedule Database
==========================================================*/

bool StorageService::loadSchedules(
    Schedule schedules[],
    uint16_t& count)
{
    if (!_ready)
    {
        return false;
    }

    count = _database.scheduleCount;

    if (count > Constants::MAX_SCHEDULES)
    {
        count = 0;
        return false;
    }

    if (count > 0)
    {
        std::memcpy(
            schedules,
            _database.schedules,
            count * sizeof(Schedule));
    }

    return true;
}

bool StorageService::saveSchedules(
    const Schedule schedules[],
    uint16_t count)
{
    if (!_ready)
    {
        return false;
    }

    if (count > Constants::MAX_SCHEDULES)
    {
        return false;
    }

    _database.scheduleCount = count;

    if (count > 0)
    {
        std::memcpy(
            _database.schedules,
            schedules,
            count * sizeof(Schedule));
    }
    else
    {
        std::memset(
            _database.schedules,
            0,
            sizeof(_database.schedules));
    }

    _dirty = true;

    return true;
}

bool StorageService::clearSchedules()
{
    if (!_ready)
    {
        return false;
    }

    _database.scheduleCount = 0;

    std::memset(
        _database.schedules,
        0,
        sizeof(_database.schedules));

    _dirty = true;

    return true;
}

/*==========================================================
    Maintenance
==========================================================*/

bool StorageService::factoryReset()
{
    if (!_ready)
    {
        return false;
    }

    initializeDatabase();

    _dirty = true;

    update();

    return true;
}

/*==========================================================
    Internal Helpers
==========================================================*/

void StorageService::createFactoryConfiguration(
    SystemConfig& config)
{
    std::memset(
        &config,
        0,
        sizeof(config));

    //------------------------------------------------------
    // Configuration Header
    //------------------------------------------------------

    config.header.version = Constants::CONFIG_VERSION;
    config.header.size    = sizeof(SystemConfig);

    //------------------------------------------------------
    // Machine
    //------------------------------------------------------

    std::strncpy(
        config.machine.name,
        Factory::MACHINE.name,
        sizeof(config.machine.name) - 1);

    config.machine.timeFormat =
        Factory::MACHINE.timeFormat;

    config.machine.wifiPasswordEnabled =
        Factory::MACHINE.wifiPasswordEnabled;

    //------------------------------------------------------
    // WiFi
    //------------------------------------------------------

    std::strncpy(
        config.wifi.ssid,
        Factory::WIFI.ssid,
        sizeof(config.wifi.ssid) - 1);

    std::strncpy(
        config.wifi.password,
        Factory::WIFI.password,
        sizeof(config.wifi.password) - 1);

    config.wifi.accessPointTimeoutMinutes =
        Factory::WIFI.accessPointTimeoutMinutes;

    //------------------------------------------------------
    // Alarm
    //------------------------------------------------------

    config.alarm = Factory::ALARM;

    //------------------------------------------------------
    // GPIO
    //------------------------------------------------------

    config.gpio = Factory::GPIO;
}

bool StorageService::validateConfiguration(
    const SystemConfig& config) const
{
    if (config.header.version != Constants::CONFIG_VERSION)
    {
        return false;
    }

    if (config.header.size != sizeof(SystemConfig))
    {
        return false;
    }

    if (std::strlen(config.machine.name) == 0)
    {
        return false;
    }

    if (config.wifi.accessPointTimeoutMinutes >
        Constants::MAX_AP_TIMEOUT_MIN)
    {
        return false;
    }

    return true;
}

} // namespace PMS
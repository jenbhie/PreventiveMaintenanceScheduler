/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * RTC Service
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#include "services/RTCService.h"

namespace PMS
{

/*==========================================================
    Constructor / Destructor
==========================================================*/

RTCService::RTCService() :
    _ready(false)
{
}

RTCService::~RTCService()
{
    end();
}

/*==========================================================
    Service
==========================================================*/

bool RTCService::begin()
{
    if (_ready)
    {
        return true;
    }

    Wire.begin();

    if (!_rtc.begin())
    {
        return false;
    }

    _ready = true;

    return true;
}

void RTCService::update()
{
    // Reserved for future synchronization tasks.
}

void RTCService::end()
{
    _ready = false;
}

bool RTCService::isReady() const
{
    return _ready;
}

/*==========================================================
    RTC Interface
==========================================================*/

bool RTCService::getDateTime(
    DateTime& dateTime)
{
    if (!_ready)
    {
        return false;
    }

    ::DateTime rtcDateTime = _rtc.now();

    dateTime = convertDateTime(rtcDateTime);

    return true;
}

bool RTCService::setDateTime(
    const DateTime& dateTime)
{
    if (!_ready)
    {
        return false;
    }

    _rtc.adjust(convertDateTime(dateTime));

    return true;
}

bool RTCService::synchronize()
{
    if (!_ready)
    {
        return false;
    }

    // Build001:
    // The DS3231 is the master clock.
    // Synchronization with clients will be implemented
    // in a later build.

    return true;
}

bool RTCService::lostPower()
{
    if (!_ready)
    {
        return true;
    }

    return _rtc.lostPower();
}

/*==========================================================
    Information
==========================================================*/

float RTCService::getTemperature()
{
    if (!_ready)
    {
        return 0.0f;
    }

    return _rtc.getTemperature();
}

/*==========================================================
    Conversion Helpers
==========================================================*/

DateTime RTCService::convertDateTime(
    const ::DateTime& rtcDateTime) const
{
    DateTime dateTime{};

    dateTime.year      = rtcDateTime.year();
    dateTime.month     = rtcDateTime.month();
    dateTime.day       = rtcDateTime.day();

    dateTime.hour      = rtcDateTime.hour();
    dateTime.minute    = rtcDateTime.minute();
    dateTime.second    = rtcDateTime.second();

    dateTime.dayOfWeek = rtcDateTime.dayOfTheWeek();

    return dateTime;
}

::DateTime RTCService::convertDateTime(
    const DateTime& dateTime) const
{
    return ::DateTime(
        dateTime.year,
        dateTime.month,
        dateTime.day,
        dateTime.hour,
        dateTime.minute,
        dateTime.second);
}

} // namespace PMS
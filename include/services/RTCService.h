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

#ifndef PMS_SERVICES_RTC_SERVICE_H
#define PMS_SERVICES_RTC_SERVICE_H

#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>

#include "../core/Types.h"

namespace PMS
{

class RTCService
{
public:

    RTCService();
    ~RTCService();

    //----------------------------------------------------------
    // Service
    //----------------------------------------------------------

    bool begin();

    void update();

    void end();

    bool isReady() const;

    //----------------------------------------------------------
    // RTC
    //----------------------------------------------------------

    bool getDateTime(DateTime& dateTime) const;

    bool setDateTime(const DateTime& dateTime);

    bool synchronize();

    //----------------------------------------------------------
    // Information
    //----------------------------------------------------------

    float getTemperature() const;

    bool lostPower() const;

private:

    RTC_DS3231 _rtc;

    bool _ready;

    DateTime convertDateTime(
        const ::DateTime& rtcDateTime) const;

    ::DateTime convertDateTime(
        const DateTime& dateTime) const;
};

}

#endif
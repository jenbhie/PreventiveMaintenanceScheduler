/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * GPIO Service
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#include "services/GPIOService.h"

namespace PMS
{

/*==========================================================
    Constructor / Destructor
==========================================================*/

GPIOService::GPIOService() :
    _ready(false)
{
}

GPIOService::~GPIOService()
{
    end();
}

/*==========================================================
    Service
==========================================================*/

bool GPIOService::begin()
{
    if (_ready)
    {
        return true;
    }

    //------------------------------------------------------
    // Outputs
    //------------------------------------------------------

    pinMode(Pins::PM_OUTPUT, OUTPUT);
    pinMode(Pins::EE_OUTPUT, OUTPUT);
    pinMode(Pins::OTHER_OUTPUT, OUTPUT);
    pinMode(Pins::COMMON_OUTPUT, OUTPUT);
    pinMode(Pins::ALARM_OUTPUT, OUTPUT);

    //------------------------------------------------------
    // Inputs
    //------------------------------------------------------

    pinMode(Pins::RESET_BUTTON, INPUT_PULLUP);
    pinMode(Pins::WIFI_BUTTON, INPUT_PULLUP);

    //------------------------------------------------------
    // Safe Startup
    //------------------------------------------------------

    setPM(false);
    setEE(false);
    setOther(false);
    setCommon(false);
    setAlarm(false);

    _ready = true;

    return true;
}

void GPIOService::update()
{
    // Build001
    // Reserved for future debounce and edge detection.
}

void GPIOService::end()
{
    if (!_ready)
    {
        return;
    }

    setPM(false);
    setEE(false);
    setOther(false);
    setCommon(false);
    setAlarm(false);

    _ready = false;
}

bool GPIOService::isReady() const
{
    return _ready;
}

/*==========================================================
    Outputs
==========================================================*/

void GPIOService::setPM(bool state)
{
    writeOutput(Factory::GPIO.pmOutput, state);
}

void GPIOService::setEE(bool state)
{
    writeOutput(Factory::GPIO.eeOutput, state);
}

void GPIOService::setOther(bool state)
{
    writeOutput(Factory::GPIO.otherOutput, state);
}

void GPIOService::setCommon(bool state)
{
    writeOutput(Factory::GPIO.commonOutput, state);
}

void GPIOService::setAlarm(bool state)
{
    writeOutput(Factory::GPIO.alarmOutput, state);
}

/*==========================================================
    Inputs
==========================================================*/

bool GPIOService::resetButtonPressed() const
{
    return readButton(Factory::GPIO.resetButton);
}

bool GPIOService::wifiButtonPressed() const
{
    return readButton(Factory::GPIO.wifiButton);
}

/*==========================================================
    Internal Helpers
==========================================================*/

void GPIOService::writeOutput(
    const OutputPin& output,
    bool state) const
{
    bool level = state;

    if (output.mode == OutputMode::ActiveLow)
    {
        level = !level;
    }

    digitalWrite(output.pin, level ? HIGH : LOW);
}

bool GPIOService::readButton(
    uint8_t pin) const
{
    // Buttons use INPUT_PULLUP.
    // Pressed = LOW.
    return digitalRead(pin) == LOW;
}

} // namespace PMS
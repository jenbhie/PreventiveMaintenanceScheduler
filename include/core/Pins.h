/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Default GPIO Assignment
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_PINS_H
#define PMS_PINS_H

#include <Arduino.h>

namespace Pins
{
    //======================================================================
    // I2C Bus
    //
    // Arduino Nano ESP32
    // Default Wire pins:
    // SDA = GPIO11
    // SCL = GPIO12
    //
    // These may be changed in Wire.begin() if required.
    //======================================================================

    inline constexpr uint8_t I2C_SDA = 11;
    inline constexpr uint8_t I2C_SCL = 12;

    //======================================================================
    // Digital Outputs (Factory Defaults)
    //======================================================================

    inline constexpr uint8_t PM_OUTPUT      = 22;

    inline constexpr uint8_t EE_OUTPUT      = 23;

    inline constexpr uint8_t OTHER_OUTPUT   = 18;

    inline constexpr uint8_t COMMON_OUTPUT  = 19;

    inline constexpr uint8_t ALARM_OUTPUT   = 21;

    //======================================================================
    // Digital Inputs
    //======================================================================

    inline constexpr uint8_t RESET_BUTTON   = 16;

    inline constexpr uint8_t WIFI_BUTTON    = 17;

    //======================================================================
    // Reserved
    //
    // Available for future expansion.
    //======================================================================

    inline constexpr uint8_t SPARE1 = 25;

    inline constexpr uint8_t SPARE2 = 26;

    inline constexpr uint8_t SPARE3 = 27;
}

#endif
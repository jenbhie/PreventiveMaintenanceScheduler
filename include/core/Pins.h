/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Default Pin Assignment
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_CORE_PINS_H
#define PMS_CORE_PINS_H

#include <Arduino.h>

namespace PMS::Pins
{
    //=========================================================
    // I2C
    //
    // Official Arduino Nano ESP32
    // These are the Arduino pin numbers used by Wire.
    //=========================================================

    inline constexpr uint8_t SDA = SDA;
    inline constexpr uint8_t SCL = SCL;

    //=========================================================
    // Digital Outputs
    //
    // Factory defaults.
    // User configurable in Settings.
    //=========================================================

    inline constexpr uint8_t PM_OUTPUT = D2;

    inline constexpr uint8_t EE_OUTPUT = D3;

    inline constexpr uint8_t OTHER_OUTPUT = D4;

    inline constexpr uint8_t COMMON_OUTPUT = D5;

    inline constexpr uint8_t ALARM_OUTPUT = D6;

    //=========================================================
    // Inputs
    //=========================================================

    inline constexpr uint8_t RESET_BUTTON = D7;

    inline constexpr uint8_t WIFI_BUTTON = D8;

    //=========================================================
    // Reserved
    //=========================================================

    inline constexpr uint8_t SPARE1 = D9;

    inline constexpr uint8_t SPARE2 = D10;
}

#endif // PMS_CORE_PINS_H
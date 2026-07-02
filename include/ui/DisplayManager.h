/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Display Manager
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_UI_DISPLAY_MANAGER_H
#define PMS_UI_DISPLAY_MANAGER_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "../model/ApplicationState.h"

namespace PMS
{

class DisplayManager
{
public:

    DisplayManager();
    ~DisplayManager();

    //----------------------------------------------------------
    // Service
    //----------------------------------------------------------

    bool begin();

    void update();

    void end();

    bool isReady() const;

    //----------------------------------------------------------
    // Display
    //----------------------------------------------------------

    void showBootScreen();

    void showStatus(
        const ApplicationState& state);

private:

    LiquidCrystal_I2C _lcd;

    bool _ready;

    uint32_t _lastRefresh;
};

}

#endif
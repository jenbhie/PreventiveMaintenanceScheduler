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

#ifndef PMS_SERVICES_GPIO_SERVICE_H
#define PMS_SERVICES_GPIO_SERVICE_H

#include <Arduino.h>

#include "../core/Config.h"

namespace PMS
{

class GPIOService
{
public:

    GPIOService();
    ~GPIOService();

    //----------------------------------------------------------
    // Service
    //----------------------------------------------------------

    bool begin();

    void update();

    void end();

    bool isReady() const;

    //----------------------------------------------------------
    // Outputs
    //----------------------------------------------------------

    void setPM(bool state);

    void setEE(bool state);

    void setOther(bool state);

    void setCommon(bool state);

    void setAlarm(bool state);

    //----------------------------------------------------------
    // Inputs
    //----------------------------------------------------------

    bool resetButtonPressed() const;

    bool wifiButtonPressed() const;

private:

    bool _ready;

    void writeOutput(
        const OutputPin& output,
        bool state) const;

    bool readButton(
        uint8_t pin) const;
};

}

#endif
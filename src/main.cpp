/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Main Entry
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#include <Arduino.h>

#include "Application.h"

PMS::Application app;

void setup()
{
    Serial.begin(115200);

    while (!Serial)
    {
        delay(10);
    }

    if (!app.begin())
    {
        Serial.println();
        Serial.println("======================================");
        Serial.println(" PMCS STARTUP FAILED");
        Serial.println("======================================");

        while (true)
        {
            delay(1000);
        }
    }

    Serial.println();
    Serial.println("======================================");
    Serial.println(" Preventive Maintenance Scheduler");
    Serial.println(" Build001 Started");
    Serial.println("======================================");
}

void loop()
{
    app.update();
}
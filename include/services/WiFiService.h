/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * WiFi Service
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_SERVICES_WIFI_SERVICE_H
#define PMS_SERVICES_WIFI_SERVICE_H

#include <Arduino.h>
#include <WiFi.h>

#include "../core/Config.h"

namespace PMS
{

class WiFiService
{
public:

    WiFiService();
    ~WiFiService();

    //----------------------------------------------------------
    // Service
    //----------------------------------------------------------

    bool begin();

    void update();

    void end();

    bool isReady() const;

    //----------------------------------------------------------
    // Access Point
    //----------------------------------------------------------

    bool startAccessPoint(
        const char* ssid,
        const char* password);

    void stopAccessPoint();

    bool isAccessPointRunning() const;

    //----------------------------------------------------------
    // Information
    //----------------------------------------------------------

    uint8_t connectedStations() const;

    IPAddress ipAddress() const;

private:

    bool _ready;

    bool _running;
};

}

#endif
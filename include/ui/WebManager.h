/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * Web Manager
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_UI_WEB_MANAGER_H
#define PMS_UI_WEB_MANAGER_H

#include <Arduino.h>
#include <WebServer.h>

#include "../model/ApplicationState.h"

namespace PMS
{

class WebManager
{
public:

    WebManager();
    ~WebManager();

    //----------------------------------------------------------
    // Service
    //----------------------------------------------------------

    bool begin();

    void update();

    void end();

    bool isReady() const;

    //----------------------------------------------------------
    // Runtime
    //----------------------------------------------------------

    void setApplicationState(
        ApplicationState* state);

private:

    WebServer _server;

    ApplicationState* _state;

    bool _ready;

    //----------------------------------------------------------
    // Route Registration
    //----------------------------------------------------------

    void registerRoutes();

    //----------------------------------------------------------
    // HTTP Handlers
    //----------------------------------------------------------

    void handleRoot();

    void handleStatus();

    void handleNotFound();
};

}

#endif
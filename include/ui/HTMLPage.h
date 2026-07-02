/******************************************************************************
 *
 * Preventive Maintenance Scheduler
 *
 * Version : 1.0
 * Build   : 001
 *
 * HTML Page
 *
 * Designed and created by
 * Jenerwin Camba
 *
 ******************************************************************************/

#ifndef PMS_UI_HTML_PAGE_H
#define PMS_UI_HTML_PAGE_H

#include <Arduino.h>

namespace PMS
{

const char INDEX_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>

<meta charset="UTF-8">

<meta name="viewport"
      content="width=device-width,initial-scale=1">

<title>Preventive Maintenance Scheduler</title>

<style>

body
{
    margin:0;
    font-family:Arial,Helvetica,sans-serif;
    background:#0f172a;
    color:white;
}

header
{
    background:#0891b2;
    padding:20px;
    text-align:center;
}

main
{
    padding:20px;
}

.card
{
    background:#1e293b;
    border-radius:10px;
    padding:20px;
    margin-bottom:15px;
}

.value
{
    font-size:22px;
    font-weight:bold;
}

footer
{
    text-align:center;
    padding:15px;
    color:#94a3b8;
}

</style>

</head>

<body>

<header>

<h2>Preventive Maintenance Scheduler</h2>

<p>Build001</p>

</header>

<main>

<div class="card">

<h3>Machine</h3>

<div id="machine"
     class="value">Loading...</div>

</div>

<div class="card">

<h3>Current Time</h3>

<div id="time"
     class="value">--:--:--</div>

</div>

<div class="card">

<h3>Alarm Status</h3>

<div id="alarm"
     class="value">Unknown</div>

</div>

</main>

<footer>

Designed and created by Jenerwin Camba

</footer>

<script>

async function updateStatus()
{
    try
    {
        const response =
            await fetch('/status');

        const data =
            await response.json();

        document.getElementById("machine").innerText =
            data.machine;

        document.getElementById("time").innerText =
            data.time;

        document.getElementById("alarm").innerText =
            data.alarm;
    }
    catch(e)
    {
        console.log(e);
    }
}

updateStatus();

setInterval(updateStatus,1000);

</script>

</body>

</html>
)rawliteral";

}

#endif
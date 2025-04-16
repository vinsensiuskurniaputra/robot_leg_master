#ifndef WIFI_CONTROLLER_H
#define WIFI_CONTROLLER_H

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Arduino.h>

class WifiController {
private:
    const char* ssid;
    const char* password;
    String com_command;
    WebServer server;

    bool d_langkah_ganti;
    bool langkah_tangga;
    bool langkah_geser;

public:
    WifiController();
    void HTTP_handleRoot(void);
    void init();
    void controlRobot();
};

#endif

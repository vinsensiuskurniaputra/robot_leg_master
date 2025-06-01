#ifndef ESPNOW_CONTROLLER_H
#define ESPNOW_CONTROLLER_H

#include <Arduino.h>
#include <esp_now.h>

class ESPNOWController {
public:
    ESPNOWController();
    void init();
    void addPeer(const uint8_t* peerAddress);
    void sendData(const uint8_t* peerAddress, const uint8_t* data, size_t len);
    void controlRobot();

private:
    static void onDataSent(const uint8_t* macAddr, esp_now_send_status_t status);
    static void onDataReceived(const uint8_t* macAddr, const uint8_t* data, int len);
};

#endif // ESPNOW_CONTROLLER_H
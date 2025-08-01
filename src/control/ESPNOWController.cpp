#include <esp_now.h>
#include <WiFi.h>
#include "control/ESPNOWController.h"
#include <control/CommandController.h>

String espnow_command = "";

ESPNOWController::ESPNOWController() {}

void ESPNOWController::init() {
    // Initialize WiFi in station mode
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    Serial.println("ESP-NOW initialized");

    // Register send and receive callbacks
    esp_now_register_send_cb(ESPNOWController::onDataSent);
    esp_now_register_recv_cb(ESPNOWController::onDataReceived);
}

void ESPNOWController::addPeer(const uint8_t* peerAddress) {
    esp_now_peer_info_t peerInfo = {};
    memcpy(peerInfo.peer_addr, peerAddress, 6);
    peerInfo.channel = 0; // Default channel
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer");
    } else {
        Serial.println("Peer added successfully");
    }
}

void ESPNOWController::sendData(const uint8_t* peerAddress, const uint8_t* data, size_t len) {
    esp_err_t result = esp_now_send(peerAddress, data, len);
    if (result == ESP_OK) {
        Serial.println("Data sent successfully");
    } else {
        Serial.println("Error sending data");
    }
}

void ESPNOWController::onDataSent(const uint8_t* macAddr, esp_now_send_status_t status) {
    Serial.print("Last Packet Send Status: ");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}

void ESPNOWController::onDataReceived(const uint8_t* macAddr, const uint8_t* data, int len) {
    Serial.print("Received data from: ");
    for (int i = 0; i < 6; i++) {
        Serial.print(macAddr[i], HEX);
        if (i < 5) Serial.print(":");
    }
    Serial.println();

    // Struktur pesan harus sesuai dengan pengirim
    struct struct_message {
        bool ultra_detected;
        bool tof_detected;
        bool dataPerintah[4];
    };

    struct_message msg;
    memset(&msg, 0, sizeof(msg));  // ✨ Clear isi struct terlebih dahulu

    // ✨ Salin hanya sebanyak len, bukan sizeof(msg)
    int copyLen = len < sizeof(msg) ? len : sizeof(msg);
    memcpy(&msg, data, copyLen);

    // ✨ Proses data yang diterima
    Serial.print("Ultrasonik Deteksi: ");
    Serial.println(msg.ultra_detected ? "YA" : "TIDAK");
    Serial.print("ToF Deteksi: ");
    Serial.println(msg.tof_detected ? "YA" : "TIDAK");

    Serial.print("Data Perintah: {");
    for (int i = 0; i < 4; i++) {
        Serial.print(msg.dataPerintah[i]);
        if (i < 3) Serial.print(", ");
    }
    Serial.println("}");

    // ✨ Tentukan perintah berdasarkan dataPerintah
    if (msg.dataPerintah[0] && msg.dataPerintah[1] && msg.dataPerintah[2] && msg.dataPerintah[3]) {
        espnow_command = "S"; // Siap
    } else if (!msg.dataPerintah[0] && !msg.dataPerintah[1] && !msg.dataPerintah[2] && msg.dataPerintah[3]) {
        espnow_command = "U"; // Maju
    } else if (msg.dataPerintah[0] && !msg.dataPerintah[1] && !msg.dataPerintah[2] && msg.dataPerintah[3]) {
        espnow_command = "B"; // Mundur
    } else if (!msg.dataPerintah[0] && !msg.dataPerintah[1] && msg.dataPerintah[2] && !msg.dataPerintah[3]) {
        espnow_command = "R"; // Putar Kanan
    } else {
        // espnow_command = ""; // Tidak ada perintah valid
    }

    Serial.print("Command received: ");
    Serial.println(espnow_command);
}


void ESPNOWController::controlRobot() {
    if (espnow_command == "S") CommandController::command(1, 1, 1, 1, 1);

    if (espnow_command == "U") maju();
    if (espnow_command == "B") mundur();
    if (espnow_command == "L") putar_kiri();
    if (espnow_command == "R") putar_kanan();

    if (espnow_command == "Q") CommandController::command(1, 1, 1, 0, 0); // Capit_turun
    if (espnow_command == "W") CommandController::command(0, 0, 0, 0, 0); // Capit_Tutup
    if (espnow_command == "I") CommandController::command(1, 1, 1, 1, 0); // Capit_Buka
    if (espnow_command == "J") CommandController::command(1, 1, 1, 0, 1); // Capit_Naik
    if (espnow_command == "Z") capit_turun_sebagian();

    // Serial.print("Command received: ");
    // Serial.println(espnow_command);

    // Reset the command after processing
    // espnow_command = "";
}
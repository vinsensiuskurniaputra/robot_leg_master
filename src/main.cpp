#include <Arduino.h>
#include "config/ServoConfig.h"
#include "control/WifiController.h"
#include "control/CommandController.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "leg_controller/TripodController.h"

ServoConfig servo;
WifiController wifi;

void task_1(void* pvParameters) {
  while (1) {
    gerak_tripod(data_k[0], data_k[1], data_k[2], data_k[3], i_sudut[0], i_sudut[1], i_sudut[2]);
    capit(kalibrasi_gripper[0][0] + kalibrasi_offset[0][0], kalibrasi_gripper[1][0] - kalibrasi_offset[1][0]);
    // pembersih(kalibrasi_gripper[0][1] - kalibrasi_offset[0][1], kalibrasi_gripper[1][1] + kalibrasi_offset[1][1]);
  }
}


void setup() {
    Serial.begin(115200);
    wifi.init();
    servo.init();
    delay(2000);
    CommandController::main_robot(); //sepertinya tidak perlu
    xTaskCreate(task_1, "task_1", 2048, NULL, 1, NULL);
}

void loop() {
    wifi.controlRobot();
}

#ifndef SERVO_CONFIG_H
#define SERVO_CONFIG_H

#include <Adafruit_PWMServoDriver.h>
#include <ESP32Servo.h>

class ServoConfig {
private:
    static const int SERVOMIN = 100;
    static const int SERVOMAX = 500;
    static const int NUM_SERVOS = 6;
    static const int SERVO_MIN = 0;
    static const int SERVO_MAX = 2400;
    static const int SERVO_FREQ = 50;
    static const uint8_t pin_servo[NUM_SERVOS];

public:
    static Adafruit_PWMServoDriver pca;
    static Servo servos[NUM_SERVOS];
    static const uint8_t pin_num_pca[2][6];

    static void init();
    static uint16_t sudut(uint16_t pos);
};

#endif

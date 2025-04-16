#include "config/ServoConfig.h"

// Static member initialization
Adafruit_PWMServoDriver ServoConfig::pca = Adafruit_PWMServoDriver(0x40);
Servo ServoConfig::servos[ServoConfig::NUM_SERVOS];
const uint8_t ServoConfig::pin_servo[ServoConfig::NUM_SERVOS] = {14, 12, 13, 4, 2, 15};
const uint8_t ServoConfig::pin_num_pca[2][6] = {
    {0, 1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10, 11},
};

void ServoConfig::init() {
    // Initialize PCA9685 PWM driver
    pca.begin();
    pca.setOscillatorFrequency(25000000);
    pca.setPWMFreq(SERVO_FREQ);

    // Allocate ESP32 PWM timers
    for (int i = 0; i < 4; i++) {
        ESP32PWM::allocateTimer(i);
    }

    // Set servo frequency and attach servos to pins
    for (int i = 0; i < NUM_SERVOS; i++) {
        servos[i].setPeriodHertz(SERVO_FREQ);
        servos[i].attach(pin_servo[i], SERVO_MIN, SERVO_MAX);
    }
}

uint16_t ServoConfig::sudut(uint16_t pos) {
    return map(pos, 0, 180, SERVOMIN, SERVOMAX);
}

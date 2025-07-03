#ifndef DATA_CONFIG_H
#define DATA_CONFIG_H

#include <Arduino.h>

// Extern arrays and variables
extern uint8_t kalibrasi_offset[2][2];
extern uint8_t kalibrasi_gripper[2][2];
extern float i_sudut[3];
extern float data_k[4];
extern int8_t tinggi[2];
extern float offset_body[2][6];
extern float timeStep[2];

// Position structure
struct Posisi {
    float x0, x1, x2, x3, x4, x5;
    float y0, y1, y2, y3, y4, y5;
};

extern Posisi posisi;
extern float totalTime;
extern int8_t offset_g[1];
extern float totalStep[2];
extern int8_t kalibrasi[3][6];
extern const uint8_t pin_command[5];

extern const uint8_t single_leg_control_data[4];

#endif
#ifndef KINEMATIC_INVERSE_H
#define KINEMATIC_INVERSE_H

#include <stdint.h>

// Inverse kinematics calculation
int8_t invers(float x, float y, float z, char com);

// Individual leg control functions
void invers_kaki_0(float x, float y, float z);
void invers_kaki_1(float x, float y, float z);
void invers_kaki_2(float x, float y, float z);
void invers_kaki_3(float x, float y, float z);
void invers_kaki_4(float x, float y, float z);
void invers_kaki_5(float x, float y, float z);

// Default leg positions
extern const int8_t default_kaki[3][6];

#endif // KINEMATIC_INVERSE_H

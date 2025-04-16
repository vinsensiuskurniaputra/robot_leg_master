#ifndef TRIPOD_CONTROLLER_H
#define TRIPOD_CONTROLLER_H
#include <Arduino.h>
    
void tripod(float x, float y, float z, float s_x, float s_y, float s_z);
void gerak_tripod(int speed, float x, float y, float z, float ss_x, float ss_y, float ss_z);

extern int8_t data_in[2][2];
extern bool il_stat[2];

#endif

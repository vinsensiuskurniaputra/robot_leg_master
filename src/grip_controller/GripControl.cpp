#include "grip_controller/GripControl.h"
#include "config/DataConfig.h"
#include <Arduino.h>
#include "config/ServoConfig.h"

void pembersih(int u_d, int o_c) {
  ServoConfig::pca.setPWM(13, 0, ServoConfig::sudut(u_d));
  ServoConfig::pca.setPWM(12, 0, ServoConfig::sudut(o_c));
}

void capit_naik() {
    kalibrasi_offset[0][0] = 120;
    delay(100);
    pembersih(45,50);
}
void capit_turun() {
    kalibrasi_offset[0][0] = 0;
    delay(100);
    pembersih(30,45);
}
void capit_turun_sebagian(){
   kalibrasi_offset[0][0] = 40;
   delay(300);
   pembersih(0,0);   
}
void capit_buka() {
  kalibrasi_offset[1][0] = 70;
}
void capit_tutup() {
  kalibrasi_offset[1][0] = 0;
}
void capit_buka_sebagian() {
  kalibrasi_offset[1][0] = 20;
}



void capit(int u_d, int o_c) {
  ServoConfig::pca.setPWM(14, 0, ServoConfig::sudut(u_d));
  ServoConfig::pca.setPWM(15, 0, ServoConfig::sudut(o_c));
}

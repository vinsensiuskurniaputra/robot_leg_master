#include <Arduino.h>
#include "config/DataConfig.h"

uint8_t kalibrasi_offset[2][2] = { 0 };
uint8_t kalibrasi_gripper[2][2] = {
  { 0, 180 },
  { 125, 0 },
};

float i_sudut[3] = { 0, 0, 0 };

/* Fungsi data_k
  data_k[0] berfungsi untuk mengatur kecepatan gerak kaki
  data_k[1] berfungsi untuk mengatur gerak robot pada sumbu x (Kanan dan Kiri)
  data_k[2] berfungsi untuk mengatur gerak robot pada sumbu y (Maju dan Mundur)
  data_k[3] berfungsi untuk mengatur gerak robot pada sumbu z (Ketinggian Robot)
*/
float data_k[4] = { 10, 0, 10, 5 };

int8_t tinggi[2] = { 0 };

//for tripod code
float offset_body[2][6] = {
  { -35, -40, -35, 35, 40, 35 },
  { 70, 0, -70, 70, 0, -70 },
};
float timeStep[2] = { 0.1, 0.095 };
Posisi posisi;
float totalTime = 1.0;
int8_t offset_g[1] = { 2 };
float totalStep[2] = {
  totalTime / timeStep[0],
  totalTime / timeStep[1],
};

/*
  Kalibrasi
  Berfungsi untuk mengatur posisi kaki robot pada saat robot dinyalakan
*/
int8_t kalibrasi[3][6] = {
  { 94, 89, 96, 84, 84, 78 }, //Servo 1
  { 89, 89, 89, 96, 94, 95 }, // Servo 2
  { 96, 97, 85, 94, 93, 95 }, // Servo 3
};


const uint8_t pin_command[5] = { 27, 26, 25, 33, 32 }; //sepertinya tidak perlu
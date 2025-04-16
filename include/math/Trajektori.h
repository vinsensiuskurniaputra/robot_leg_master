#ifndef TRAJEKTORI_H
#define TRAJEKTORI_H

float hitung(float awal, float dat, float t);
float hitung_selisih_posisi(float awal, float akhir, float totalTime);
void trajektori(float i, float timeStep, float x_awal, float x_akhir, float y_awal, float y_akhir, float z_tinggi, int kaki, char com, float totalTime, float s_x, float s_y, float s_z);

#endif

#include <math.h>
#include "config/DataConfig.h"
#include "math/Rotation.h"
#include "math/KinematicInverse.h"
#include "math/Trajektori.h"

float hitung(float awal, float dat, float t) {
    return awal + (dat * t);
}

float hitung_selisih_posisi(float awal, float akhir, float totalTime) {
    return (akhir - awal) / totalTime;
}

void trajektori(float i, float timeStep, float x_awal, float x_akhir, float y_awal, float y_akhir, float z_tinggi, int kaki, char com, float totalTime, float s_x, float s_y, float s_z) {
  float t = i * timeStep;
  float
    a = pow((1 - t), 3),
    b = 3 * t * pow((1 - t), 2),
    c = 3 * pow(t, 2) * (1 - t),
    d = pow(t, 3);

  float v0x = hitung_selisih_posisi(x_awal, x_akhir, totalTime);
  float v0y = hitung_selisih_posisi(y_awal, y_akhir, totalTime);

  if (kaki == 0) {
    float px_0 = rotasi(0, 0, 0, offset_body[0][0], offset_body[1][0], s_x, s_y, s_z, 'x');
    float py_0 = rotasi(0, 0, 0, offset_body[0][0], offset_body[1][0], s_x, s_y, s_z, 'y');
    float pz_0 = rotasi(0, 0, 0, offset_body[0][0], offset_body[1][0], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_0(default_kaki[0][0] - px - px_0, default_kaki[1][0] + py + py_0, default_kaki[2][0] - pz - pz_0 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_0(default_kaki[0][0] - px - px_0, default_kaki[1][0] + py + py_0, default_kaki[2][0] - pz - pz_0 + tinggi[0]);
    }
  }
  if (kaki == 1) {
    float px_1 = rotasi(0, 0, 0, offset_body[0][1], offset_body[1][1], s_x, s_y, s_z, 'x');
    float py_1 = rotasi(0, 0, 0, offset_body[0][1], offset_body[1][1], s_x, s_y, s_z, 'y');
    float pz_1 = rotasi(0, 0, 0, offset_body[0][1], offset_body[1][1], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_1(default_kaki[0][1] - px - px_1, default_kaki[1][1] + py + py_1, default_kaki[2][1] - pz - pz_1 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_1(default_kaki[0][1] - px - px_1, default_kaki[1][1] + py + py_1, default_kaki[2][1] - pz - pz_1 + tinggi[0]);
    }
  }
  if (kaki == 2) {
    float px_2 = rotasi(0, 0, 0, offset_body[0][2], offset_body[1][2], s_x, s_y, s_z, 'x');
    float py_2 = rotasi(0, 0, 0, offset_body[0][2], offset_body[1][2], s_x, s_y, s_z, 'y');
    float pz_2 = rotasi(0, 0, 0, offset_body[0][2], offset_body[1][2], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_2(default_kaki[0][2] - px - px_2, default_kaki[1][2] + py + py_2, default_kaki[2][2] - pz - pz_2 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_2(default_kaki[0][2] - px - px_2, default_kaki[1][2] + py + py_2, default_kaki[2][2] - pz - pz_2 + tinggi[0]);
    }
  }
  if (kaki == 3) {
    float px_3 = rotasi(0, 0, 0, offset_body[0][3], offset_body[1][3], s_x, s_y, s_z, 'x');
    float py_3 = rotasi(0, 0, 0, offset_body[0][3], offset_body[1][3], s_x, s_y, s_z, 'y');
    float pz_3 = rotasi(0, 0, 0, offset_body[0][3], offset_body[1][3], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_3(default_kaki[0][3] + px + px_3, default_kaki[1][3] + py + py_3, default_kaki[2][3] - pz - pz_3 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_3(default_kaki[0][3] + px + px_3, default_kaki[1][3] + py + py_3, default_kaki[2][3] - pz - pz_3 + tinggi[0]);
    }
  }
  if (kaki == 4) {
    float px_4 = rotasi(0, 0, 0, offset_body[0][4], offset_body[1][4], s_x, s_y, s_z, 'x');
    float py_4 = rotasi(0, 0, 0, offset_body[0][4], offset_body[1][4], s_x, s_y, s_z, 'y');
    float pz_4 = rotasi(0, 0, 0, offset_body[0][4], offset_body[1][4], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_4(default_kaki[0][4] + px + px_4, default_kaki[1][4] + py + py_4, default_kaki[2][4] - pz - pz_4 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_4(default_kaki[0][4] + px + px_4, default_kaki[1][4] + py + py_4, default_kaki[2][4] - pz - pz_4 + tinggi[0]);
    }
  }
  if (kaki == 5) {
    float px_5 = rotasi(0, 0, 0, offset_body[0][5], offset_body[1][5], s_x, s_y, s_z, 'x');
    float py_5 = rotasi(0, 0, 0, offset_body[0][5], offset_body[1][5], s_x, s_y, s_z, 'y');
    float pz_5 = rotasi(0, 0, 0, offset_body[0][5], offset_body[1][5], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_5(default_kaki[0][5] + px + px_5, default_kaki[1][5] + py + py_5, default_kaki[2][5] - pz - pz_5 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_5(default_kaki[0][5] + px + px_5, default_kaki[1][5] + py + py_5, default_kaki[2][5] - pz - pz_5 + tinggi[0]);
    }
  }
}
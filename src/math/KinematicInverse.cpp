#include "math/KinematicInverse.h"
#include <Arduino.h>
#include "config/ServoConfig.h"
#include "config/DataConfig.h"
#include "math/Rotation.h"

const int8_t default_kaki[3][6] = {
    { 60, 60, 60, 60, 60, 60 },
    { 35, 0, -35, 35, 0, -35 },
    { 50, 50, 50, 50, 50, 50 },
};

// --> PERHITUNGAN INVERS KINEMATIK
int8_t invers(float x, float y, float z, char com) {
  float
    radian = 180 / PI,
    femurLength = 60.00,
    tibiaLength = 50.00,
    coxa_Length = 25.00;

  float legLength = sqrt(pow(x, 2) + pow(y, 2));
  float Z_Length = sqrt(pow(z, 2) + pow((legLength - coxa_Length), 2));
  float Sud_A = atan(legLength / z) * radian;
  float Sud_B = acos((pow(femurLength, 2) + pow(Z_Length, 2) - pow(tibiaLength, 2)) / (2 * femurLength * Z_Length)) * radian;
  float Sud_C = acos((pow(femurLength, 2) + pow(tibiaLength, 2) - pow(Z_Length, 2)) / (2 * femurLength * tibiaLength)) * radian;
  if (com == 'A') {
    int8_t Alpha = atan(y / x) * radian;
    return Alpha;
  } else if (com == 'B') {
    int8_t Betha = (Sud_A + Sud_B) - 98;
    return Betha;
  } else if (com == 'G') {
    int8_t Gamma = Sud_C - 66;
    return Gamma;
  } else {
    return 0;
  }
}

// --> EKSEKUSI GERAK KAKI 0
void invers_kaki_0(float x, float y, float z) {
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[0][0], 0, ServoConfig::sudut(kalibrasi[0][0] + invers(x, y, z, 'A')));
  ServoConfig::servos[0].write(kalibrasi[1][0] + invers(x, y, z, 'B'));
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[1][0], 0, ServoConfig::sudut(kalibrasi[2][0] - invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 1
void invers_kaki_1(float x, float y, float z) {
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[0][1], 0, ServoConfig::sudut(kalibrasi[0][1] + invers(x, y, z, 'A')));
  ServoConfig::servos[1].write(kalibrasi[1][1] + invers(x, y, z, 'B'));
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[1][1], 0, ServoConfig::sudut(kalibrasi[2][1] - invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 2
void invers_kaki_2(float x, float y, float z) {
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[0][2], 0, ServoConfig::sudut(kalibrasi[0][2] + invers(x, y, z, 'A')));
  ServoConfig::servos[2].write(kalibrasi[1][2] + invers(x, y, z, 'B'));
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[1][2], 0, ServoConfig::sudut(kalibrasi[2][2] - invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 3
void invers_kaki_3(float x, float y, float z) {
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[0][3], 0, ServoConfig::sudut(kalibrasi[0][3] - invers(x, y, z, 'A')));
  ServoConfig::servos[3].write(kalibrasi[1][3] - invers(x, y, z, 'B'));
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[1][3], 0, ServoConfig::sudut(kalibrasi[2][3] + invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 4
void invers_kaki_4(float x, float y, float z) {
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[0][4], 0, ServoConfig::sudut(kalibrasi[0][4] - invers(x, y, z, 'A')));
  ServoConfig::servos[4].write(kalibrasi[1][4] - invers(x, y, z, 'B'));
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[1][4], 0, ServoConfig::sudut(kalibrasi[2][4] + invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 5
void invers_kaki_5(float x, float y, float z) {
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[0][5], 0, ServoConfig::sudut(kalibrasi[0][5] - invers(x, y, z, 'A')));
  ServoConfig::servos[5].write(kalibrasi[1][5] - invers(x, y, z, 'B'));
  ServoConfig::pca.setPWM(ServoConfig::pin_num_pca[1][5], 0, ServoConfig::sudut(kalibrasi[2][5] + invers(x, y, z, 'G')));
}



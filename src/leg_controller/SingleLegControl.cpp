#include "leg_controller/SingleLegControl.h"
#include "math/KinematicInverse.h"
#include "math/Rotation.h"
#include "config/DataConfig.h"
#include "config/ServoConfig.h"
#include <Arduino.h>

void control_single_leg(int leg_index, float x, float y, float z) {
  // Check if leg_index is valid (0-5)
  if (leg_index < 0 || leg_index > 5) {
    Serial.println("Invalid leg index. Must be between 0-5.");
    return;
  }
  
  // Apply rotation adjustments for the specific leg
  float px = 0, py = 0, pz = 0;
  
  // Calculate rotations based on offset for the specific leg
  px = rotasi(0, 0, 0, offset_body[0][leg_index], offset_body[1][leg_index], 0, 0, 0, 'x');
  py = rotasi(0, 0, 0, offset_body[0][leg_index], offset_body[1][leg_index], 0, 0, 0, 'y');
  pz = rotasi(0, 0, 0, offset_body[0][leg_index], offset_body[1][leg_index], 0, 0, 0, 'z');
  
  // Based on which side the leg is on (left or right), adjust coordinates
  if (leg_index < 3) {  // Legs 0, 1, 2 (right side)
    switch (leg_index) {
      case 0:
        invers_kaki_0(default_kaki[0][0] - x - px, default_kaki[1][0] + y + py, default_kaki[2][0] - z - pz);
        break;
      case 1:
        invers_kaki_1(default_kaki[0][1] - x - px, default_kaki[1][1] + y + py, default_kaki[2][1] - z - pz);
        break;
      case 2:
        invers_kaki_2(default_kaki[0][2] - x - px, default_kaki[1][2] + y + py, default_kaki[2][2] - z - pz);
        break;
    }
  } else {  // Legs 3, 4, 5 (left side)
    switch (leg_index) {
      case 3:
        invers_kaki_3(default_kaki[0][3] + x + px, default_kaki[1][3] + y + py, default_kaki[2][3] - z - pz);
        break;
      case 4:
        invers_kaki_4(default_kaki[0][4] + x + px, default_kaki[1][4] + y + py, default_kaki[2][4] - z - pz);
        break;
      case 5:
        invers_kaki_5(default_kaki[0][5] + x + px, default_kaki[1][5] + y + py, default_kaki[2][5] - z - pz);
        break;
    }
  }
}

void leg_circle_pattern(int leg_index, float radius, float height, int cycles) {
  // Check if leg_index is valid (0-5)
  if (leg_index < 0 || leg_index > 5) {
    Serial.println("Invalid leg index. Must be between 0-5.");
    return;
  }

  // Perform circular movement
  const int steps = 36; // 36 points per circle for smooth motion
  
  for (int c = 0; c < cycles; c++) {
    for (int i = 0; i < steps; i++) {
      float angle = (i * 2.0 * PI) / steps;
      float x = radius * cos(angle);
      float y = radius * sin(angle);
      float z = height;
      
      control_single_leg(leg_index, x, y, z);
      delay(30); // Small delay for smoother movement
    }
  }
}

void leg_rectangle_pattern(int leg_index, float width, float length, float height) {
  // Check if leg_index is valid (0-5)
  if (leg_index < 0 || leg_index > 5) {
    Serial.println("Invalid leg index. Must be between 0-5.");
    return;
  }

  // Define the rectangle corners
  float x_points[4] = {width/2, width/2, -width/2, -width/2};
  float y_points[4] = {length/2, -length/2, -length/2, length/2};
  const int steps_per_side = 10;
  
  // Move through the rectangle
  for (int i = 0; i < 4; i++) {
    int next_i = (i + 1) % 4;
    
    for (int step = 0; step < steps_per_side; step++) {
      float t = (float)step / steps_per_side;
      float x = x_points[i] + t * (x_points[next_i] - x_points[i]);
      float y = y_points[i] + t * (y_points[next_i] - y_points[i]);
      
      control_single_leg(leg_index, x, y, height);
      delay(40);
    }
  }
}

void leg_single_step(int leg_index, float x_dist, float y_dist, float height) {
  // Check if leg_index is valid (0-5)
  if (leg_index < 0 || leg_index > 5) {
    Serial.println("Invalid leg index. Must be between 0-5.");
    return;
  }
  
  // Step 1: Lift leg
  for (int i = 0; i <= 10; i++) {
    float t = i / 10.0;
    float current_height = t * height;
    control_single_leg(leg_index, 0, 0, current_height);
    delay(20);
  }
  
  // Step 2: Move leg forward/sideways while up
  for (int i = 0; i <= 10; i++) {
    float t = i / 10.0;
    float current_x = t * x_dist;
    float current_y = t * y_dist;
    control_single_leg(leg_index, current_x, current_y, height);
    delay(20);
  }
  
  // Step 3: Put leg down at new position
  for (int i = 10; i >= 0; i--) {
    float t = i / 10.0;
    float current_height = t * height;
    control_single_leg(leg_index, x_dist, y_dist, current_height);
    delay(20);
  }
}

void reset_leg_position(int leg_index) {
  // Check if leg_index is valid (0-5)
  if (leg_index < 0 || leg_index > 5) {
    Serial.println("Invalid leg index. Must be between 0-5.");
    return;
  }
  
  // Move leg smoothly back to default position
  control_single_leg(leg_index, 0, 0, 0);
}

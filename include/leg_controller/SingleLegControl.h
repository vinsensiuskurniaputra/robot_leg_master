#ifndef SINGLE_LEG_CONTROL_H
#define SINGLE_LEG_CONTROL_H

#include <Arduino.h>

/**
 * Control a single leg by moving it to a specific position
 * 
 * @param leg_index The leg to control (0-5)
 * @param x X coordinate offset
 * @param y Y coordinate offset
 * @param z Z coordinate offset (height)
 */
void control_single_leg(int leg_index, float x, float y, float z);

/**
 * Move a leg in a circular pattern
 * 
 * @param leg_index The leg to control (0-5)
 * @param radius The radius of the circle
 * @param height The height of the leg movement
 * @param cycles How many circles to complete
 */
void leg_circle_pattern(int leg_index, float radius, float height, int cycles);

/**
 * Move a leg in a rectangular pattern
 * 
 * @param leg_index The leg to control (0-5)
 * @param width Width of the rectangle
 * @param length Length of the rectangle
 * @param height The height of the leg movement
 */
void leg_rectangle_pattern(int leg_index, float width, float length, float height);

/**
 * Perform a single step with one leg (lift, move, place)
 * 
 * @param leg_index The leg to control (0-5)
 * @param x_dist Forward/backward distance
 * @param y_dist Left/right distance
 * @param height Step height
 */
void leg_single_step(int leg_index, float x_dist, float y_dist, float height);

/**
 * Reset a leg to its default position
 * 
 * @param leg_index The leg to reset (0-5)
 */
void reset_leg_position(int leg_index);

#endif // SINGLE_LEG_CONTROL_H

#ifndef FLOOR_H
#define FLOOR_H

#include <GL/glut.h>

/**
 * @brief Draws a floor with opposite corners as (x1, 0, z1) and (x2, 0, z2);
 * Floor always has y = 0
 * 
 * @param x1, z1, x2, z2 Coordinates as described
 */
void draw_floor(float x1, float z1, float x2, float z2);

#endif
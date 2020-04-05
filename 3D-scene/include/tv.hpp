#ifndef TV_H
#define TV_H

#include <GL/glut.h>

/**
 * @brief Draws a floor with opposite corners as (x1, 0, z1) and (x2, 0, z2);
 * Floor always has y = 0
 * 
 * @param x1, z1, x2, z2 Coordinates as described
 */
void draw_tv();

#endif
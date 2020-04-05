#ifndef WALL_H
#define WALL_H

#include <GL/glut.h>

/**
 * @brief Draws walls and ceiling. Entrance provided on the wall towards positive z
 * 
 * @param x1 
 * @param z1 
 * @param x2 
 * @param z2 
 * @param ceilHeight 
 */
void draw_walls(float x1, float z1, float x2, float z2, float ceilHeight);

#endif
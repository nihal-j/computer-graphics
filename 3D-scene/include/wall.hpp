#ifndef WALL_H
#define WALL_H

#include <GL/glut.h>

/**
 * @brief Draws walls and ceiling. Entrance provided on the wall towards positive z
 * 
 * @param x1 left bottom corner x of floor
 * @param z1 left bottom corner z of floor
 * @param x2 right top corner x of floor
 * @param z2 right top corner z of floor
 * @param ceilHeight height of walls
 */
void draw_walls(float x1, float z1, float x2, float z2, float ceilHeight);

#endif
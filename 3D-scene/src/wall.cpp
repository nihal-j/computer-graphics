#include "wall.hpp"
#include <iostream>

void draw_walls(float x1, float z1, float x2, float z2, float ceilHeight)
{
    GLfloat vertices[] =
    {
        x1, 0, z1, // 0
        x1, ceilHeight, z1, // 1
        x1, ceilHeight, z2, // 2
        x1, 0, z2, // 3
        x2, ceilHeight, z2, // 4
        x2, 0, z2, // 5
        x2, 0, z1, // 6
        x2, ceilHeight, z1 // 7
    };
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    int indices[][4] = 
    {
        {0, 1, 2, 3}, // left
        {3, 5, 4, 2}, // back
        {6, 5, 4, 7}, // right
        {1, 7, 4, 2}, // ceil
        {0, 6, 7, 1}  // front
    }; 

    // left wall
    glColor3f(0.160f, 0.015f, 0.184f);  // dark purple
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, indices[0]);

    // back wall
    glColor3f(0.988f, 0.976f, 0.450f);  // light yellow
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, indices[1]);

    // // right wall
    // glColor3f(0.988f, 0.976f, 0.450f);  // light yellow
    // glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, indices[2]);
    
    // // ceiling
    // glColor3f(0.780f, 0.705f, 0.619f);  // peach
    // glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, indices[3]);

    // front
    // glColor3f(0.988f, 0.976f, 0.450f);  // light yellow
    // glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, indices[4]);

    float halfway = (x2 - x1)*0.5f;
    float doorWidth = (x2 - x1)*0.2f, doorHeight = doorWidth*1.3f;
    float frontWall[] = 
    {
        x1, 0, z1, // 0
        x1 + halfway, 0, z1, // 1
        x1 + halfway, doorHeight, z1, // 2
        x1 + halfway + doorWidth, doorHeight, z1, // 3 
        x1 + halfway + doorWidth, 0, z1, // 4
        x2, 0, z1, // 5
        x2, ceilHeight, z1, // 6
        x1 + halfway + doorWidth, ceilHeight, z1, // 7
        x1 + halfway, ceilHeight, z1, // 8
        x1, ceilHeight, z1 // 9
    };
    int fIndices[][4] = 
    {
        {0, 1, 8, 9},
        {2, 3, 7, 8},
        {4, 5, 6, 7}
    };
    glColor3f(0.988f, 0.976f, 0.450f);  // light yellow
    glVertexPointer(3, GL_FLOAT, 0, frontWall);
    // for (int i = 0; i < 3; i++)
    //     glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, fIndices[i]);
}
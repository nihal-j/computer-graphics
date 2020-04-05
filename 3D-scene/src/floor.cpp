#include "floor.hpp"

void draw_floor(float x1, float z1, float x2, float z2)
{
    GLfloat vertices[] = 
    {
        x2, 0, z2,
        x1, 0, z2,
        x1, 0, z1,
        x2, 0, z1
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    int indices[] = {0, 1, 2, 3}; 
    glColor3f(0.768f, 0.643f, 0.392f);  // peach
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, indices);
}
#include "dining.hpp"

void draw_dining()
{
    glPushMatrix();
    {
        // table
        glTranslatef(0, 0, 0);
        glScalef(0.5f, 0.5f, 0.5f);
        draw_table();
    }
    glPopMatrix();

    glPushMatrix();
    {
        // chair 1
        glTranslatef(6, 0, 0);
        glRotatef(-90.0f, 0, 1, 0);
        glScalef(0.4f, 0.4f, 0.4f);
        draw_chair();
    }
    glPopMatrix();
    glPushMatrix();
    {
        // chair 2
        glTranslatef(-6, 0, 0);
        glRotatef(90.0f, 0, 1, 0);
        glScalef(0.4f, 0.4f, 0.4f);
        draw_chair();
    }
    glPopMatrix();
    glPushMatrix();
    {
        // chair 3
        glTranslatef(0, 0, -6);
        glScalef(0.4f, 0.4f, 0.4f);
        draw_chair();
    }
    glPopMatrix();
    glPushMatrix();
    {
        // chair 4
        glTranslatef(0, 0, 6);
        glRotatef(180.0f, 0, 1, 0);
        glScalef(0.4f, 0.4f, 0.4f);
        draw_chair();
    }
    glPopMatrix();
    glPushMatrix();
    {
        // teapot
        glColor3f(1.0f, 0.215f, 0.0f);      // magenta
        glTranslatef(0, 4.7f, 0);
        glutSolidTeapot(1.0);
    }
    glPopMatrix();
}
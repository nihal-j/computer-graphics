#include "chair.hpp"

void draw_chair()
{
    glPushMatrix();
    {
        glColor3f(0.827f, 0.478f, 0.070f);      // orangeish brown
        glPushMatrix();
        {
            // leg 1
            glTranslatef(-3, 4, -3);
            glScalef(1, 4, 1);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // leg 2
            glTranslatef(3, 4, -3);
            glScalef(1, 4, 1);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // leg 3
            glTranslatef(3, 4, 3);
            glScalef(1, 4, 1);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // leg
            glTranslatef(-3, 4, 3);
            glScalef(1, 4, 1);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // seat
            glTranslatef(0, 9, 0);
            glScalef(4, 1, 4);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // back
            glTranslatef(0, 11, -3.5);
            glScalef(4, 6, 0.5);
            glutSolidCube(2.0);
        }
        glPopMatrix();
    }
    glPopMatrix();
}
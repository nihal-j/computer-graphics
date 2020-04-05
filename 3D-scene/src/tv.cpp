#include "tv.hpp"

void draw_tv()
{
    glPushMatrix();
    {
        glPushMatrix();
        {
            // tv back
            glColor3f(1, 1, 1);
            // glTranslatef(0, 8, -29);
            glScalef(8, 8, 1);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // right 1
            glColor3f(1, 1, 1);
            glTranslatef(13.5, 0, 0.5);
            glScalef(2.5, 0.5, 1.5);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // right 2
            glColor3f(1, 1, 1);
            glTranslatef(13.5, 6, 0.5);
            glScalef(2.5, 0.5, 1.5);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // right 3
            glColor3f(1, 1, 1);
            glTranslatef(13.5, -6, 0.5);
            glScalef(2.5, 0.5, 1.5);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // left 1
            glColor3f(1, 1, 1);
            glTranslatef(-13.5, 0, 0.5);
            glScalef(2.5, 0.5, 1.5);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // left 2
            glColor3f(1, 1, 1);
            glTranslatef(-13.5, 6, 0.5);
            glScalef(2.5, 0.5, 1.5);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // left 3
            glColor3f(1, 1, 1);
            glTranslatef(-13.5, -6, 0.5);
            glScalef(2.5, 0.5, 1.5);
            glutSolidCube(2.0);
        }
        glPopMatrix();
    }
    glPopMatrix();
}
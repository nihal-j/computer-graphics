#include "table.hpp"

void draw_table()
{
    glPushMatrix();
    {
        glColor3f(0.341f, 0.219f, 0.078f);      // brown
        glPushMatrix();
        {
            // leg
            glTranslatef(-3, 3, -3);
            glScalef(1, 3, 1);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // leg
            glTranslatef(3, 3, -3);
            glScalef(1, 3, 1);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // leg
            glTranslatef(-3, 3, 3);
            glScalef(1, 3, 1);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // leg
            glTranslatef(3, 3, 3);
            glScalef(1, 3, 1);
            glutSolidCube(2.0);
        }
        glPopMatrix();
        glPushMatrix();
        {
            // top
            glTranslatef(0, 7, 0);
            glScalef(8, 1, 8);
            glutSolidCube(2.0);
        }   
        glPopMatrix();
    }
    glPopMatrix();
}
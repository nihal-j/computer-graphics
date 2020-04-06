#include "cupboard.hpp"

void draw_cupboard(Object &cupboard, Object &door, Object &knob)
{
    cupboard.draw();
    glColor3f(0.815f, 0.984f, 0.976f);
    door.draw();
    glColor3f(1, 1, 1);
    knob.draw();
}
#include <iostream>
#include "line.h"
#include "screen.h"

Line::Line(int startX, int startY, int endX, int endY)
{
    Line::rasterize_line(startX, startY, endX, endY);
    return;
}

void Line::store_point(int x, int y)
{
    points[pointCount*3] = (float)x;
    points[pointCount*3 + 1] = (float)y;
    points[pointCount*3 + 2] = 0.0f;
    pointCount++;
    return;
}

void Line::rasterize_line(int startX, int startY, int endX, int endY)
{
    int dx = endX - startX;
    int dy = endY - startY;

    int d = (2 * dy) - dx;

    int incrE = 2 * dy;
    int incrNE = 2 * (dy - dx);

    int x = startX, y = startY;
    
    Line::store_point(x, y);

    while (x <= endX)
    {
        if (d <= 0)
        {
            // Choose E pixel
            d += incrE;
            x++;
        }
        else
        {
            // choose NE pixel
            d += incrNE;
            x++; y++;
        }
        Line::store_point(x, y);
    }
}

/* DEBUG 
// /

int main()
{
    Line line(0, 0, 200, 200);
    float* points = line.get_line();
    int pointCount = line.get_count();

    std::cout << pointCount << "\n";

    return 0;
}

// */
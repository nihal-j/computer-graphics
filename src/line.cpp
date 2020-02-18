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
    int x = startX, y = startY;

    int sign = dy >= 0 ? 1 : -1;
    
    Line::store_point(x, y);

    while (x < endX)
    {
        if (d * sign > 0)
        {
            y += sign;
            d -= 2 * dx * sign;
        }
        d += 2 * dy;
        x++;
        Line::store_point(x, y);
    }
}

void Line::print_line(int startIdx, int count)
{
    for (int i = startIdx; i <= startIdx + count - 1; i++)
        std::cout << points[i*3] << ", " << points[i*3 + 1] << ", " << points[i*3 + 2] << "\n";
}

/* DEBUG 
// /

int main()
{
    Line line(400, 400, 600, 300);
    int* points = line.get_line();
    int pointCount = line.get_count();

    line.print_line(pointCount - 10, 10);

    return 0;
}

// */
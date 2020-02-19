#include <iostream>
#include "circle.h"
#include "screen.h"

Circle::Circle(int cX, int cY, int radius)
{
    this -> cX = cX;
    this -> cY = cY;
    this -> radius = radius;

    pointCount = 0;

    Circle::scan_convert_circle();
}

void Circle::store_point(int x, int y)
{
    points[pointCount*3] = (float)x;
    points[pointCount*3 + 1] = (float)y;
    points[pointCount*3 + 2] = 0.0f;
    pointCount++;
    return;
}

void Circle::symmetric_store_point(int x, int y)
{
    // x and y are relative to cx and cy.

    store_point(x + cX, y + cY);
    store_point(x + cX, -y + cY);
    store_point(-x + cX, y + cY);
    store_point(-x + cX, -y + cY);
    store_point(y + cX, x + cY);
    store_point(y + cX, -x + cY);
    store_point(-y + cX, x + cY);
    store_point(-y + cX, -x + cY);
}

void Circle::scan_convert_circle()
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    symmetric_store_point(x, y);

    int deltaE = 3;
    int deltaSE = -2 * radius + 5;

    while (y > x)
    {
        if (d < 0)
        {
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;
        }
        else
        {
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            y--;
        }
        x++;
        symmetric_store_point(x, y);
    }
}

void Circle::print_circle(int startIdx, int count)
{
    for (int i = startIdx; i <= startIdx + count - 1; i++)
        std::cout << points[i*3] << ", " << points[i*3 + 1] << ", " << points[i*3 + 2] << "\n";
}

/* DEBUG 
// /

int main()
{
    Circle circle(400, 400, 100);
    int *points = circle.get_circle();
    int pointCount = circle.get_count();

    std::cout << pointCount << "\n";

    circle.print_circle(0, pointCount);
}

// */
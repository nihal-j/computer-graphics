#include "image.hpp"

int main()
{
    Image img(640, 480);
    for (int y = 0; y < 480; y++)
        for (int x = 0; x < 640; x++)
            img.set_pixel(x, y, (unsigned char)(((float)x/640.0)*255), 0, 0);

    img.to_file("img.bmp");
    return 0;
}
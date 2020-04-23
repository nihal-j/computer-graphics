#include "image.hpp"
#include "color.hpp"

int main()
{
    Image img(640, 480);
    Color color;
    for (int y = 0; y < 480; y++)
    {
        for (int x = 0; x < 640; x++)
        {
            double h = x/640.0, s = y/480.0;
            double v = 1.0;

            unsigned char hB = static_cast<unsigned char>(h*255.0);
            unsigned char sB = static_cast<unsigned char>(s*255.0);
            unsigned char vB = static_cast<unsigned char>(v*255.0);

            color.setHSV(hB, sB, vB);
            img.set_pixel(x, y, color.getRed(), color.getBlue(), color.getGreen());
        }
    }

    img.to_file("img/img_hsv.bmp");
    return 0;
}
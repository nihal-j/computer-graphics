#include "color.hpp"
#include <cmath>

Color::Color()
{
    red = 0.0;
    blue = 0.0;
    green = 0.0;
    hue = 0.0;
    saturation = 0.0;
    value = 0.0;
}

void Color::setRGB(unsigned char red, unsigned char blue, unsigned char green)
{
    this -> red = static_cast<double>(red) / 255.0; 
    this -> blue = static_cast<double>(blue) / 255.0; 
    this -> green = static_cast<double>(green) / 255.0;
    computeHSV();
}

void Color::setHSV(unsigned char hue, unsigned char saturation, unsigned char value)
{
    this -> hue = static_cast<double>(hue) / 255.0 * 360.0;
    this -> saturation = static_cast<double>(saturation) / 255.0;
    this -> value = static_cast<double>(value) / 255.0;
    computeRGB();
}

void Color::computeHSV()
{
    
}

void Color::computeRGB()
{
    double c = saturation*value;
    double hue_ = hue/60.0;
    double x1 = fmod(hue_, 1.0);
    double x2 = 1.0 - x1;

    if (hue_ >= 0 && hue_ < 1)
    {
        red = c;
        green = x1*c;
        blue = 0.0;
    }
    else if (hue_ >= 1 && hue_ < 2)
    {
        red = x2*c;
        green = c;
        blue = 0.0;
    }
    else if (hue_ >= 2 && hue_ < 3)
    {
        red = 0.0;
        green = c;
        blue = x1*c;
    }
    else if (hue_ >= 3 && hue_ < 4)
    {
        red = 0.0;
        green = x2*c;
        blue = c;
    }
    else if (hue_ >= 4 && hue_ < 5)
    {
        red = x1*c;
        green = 0.0;
        blue = c;
    }
    else if (hue_ >= 5 && hue_ < 6)
    {
        red = c;
        green = 0.0;
        blue = x2*c;
    }
    else
    {
        red = 0.0;
        green = 0.0;
        blue = 0.0;
    }

    double m = value - c;
    red += m;
    green += m;
    blue += m;
}
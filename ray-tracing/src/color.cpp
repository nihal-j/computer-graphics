#include "color.hpp"

Color::Color()
{
    red = 0.0;
    blue = 0.0;
    green = 0.0;
    hue = 0.0;
    saturation = 0.0;
    value = 0.0;
}

Color::Color(double red, double green, double blue)
{
    this -> red = red;
    this -> green = green;
    this -> blue = blue;
    computeHSV();
}

void Color::setRGB(unsigned char red, unsigned char blue, unsigned char green)
{
    // take the byte values and convert to 0..1
    this -> red = static_cast<double>(red) / 255.0; 
    this -> blue = static_cast<double>(blue) / 255.0; 
    this -> green = static_cast<double>(green) / 255.0;
    computeHSV();
}

void Color::setHSV(unsigned char hue, unsigned char saturation, unsigned char value)
{
    // take the byte values and convert to 0..1 (except hue which is to 0..360)
    this -> hue = static_cast<double>(hue) / 255.0 * 360.0;
    this -> saturation = static_cast<double>(saturation) / 255.0;
    this -> value = static_cast<double>(value) / 255.0;
    computeRGB();
}

void Color::setRGB(double red, double green, double blue)
{
    // set values directly to 0..1
    this -> red = red;
    this -> green = green;
    this -> blue = blue;
    // convert to HSV
    computeHSV();
}

void Color::setHSV(double hue, double saturation, double value)
{
    // set values directly to 0..1 (except hue which is 0..360)
    this -> hue = hue;
    this -> saturation = saturation;
    this -> value = value;
    // convert to RGB
    computeRGB();
}

void Color::computeHSV()
{
    // convert RGB to HSV
    int index;
    double mx, mn;

    if (red == green && red == blue)
    {
        index = 0;
        mx = red;
        mn = red;
    }
    else if (red > green && red > blue)
    {
        index = 1;
        mx = red;
        mn = std::min(blue, green);
    }
    else if (green > blue && green > red)
    {
        index = 2;
        mx = green;
        mn = std::min(red, blue);
    }
    else
    {
        index = 3;
        mx = blue;
        mn = std::min(red, green);
    }

    double h;
    switch(index)
    {
        case 0:     h = 0; break;
        case 1:     h = 60.0 * (green - blue) / (mx - mn); break;
        case 2:     h = 60.0 * (2 + ((blue - red) / (mx - mn))); break;
        case 3:     h = 60.0 * (4 + ((red - green) / (mx - mn))); break;
    }

    double s = (index == 0) ? 0.0 : (mx - mn)/mx;
    double v = mx;

    hue = h;
    saturation = s;
    value = v;    
}

void Color::computeRGB()
{
    // convert to RGB
    // algorithm from Wikipedia
    
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
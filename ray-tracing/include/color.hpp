#ifndef COLOR_HPP
#define COLOR_HPP

#include <algorithm>
#include <iostream>
#include <cmath>

class Color
{
    public:
        Color();

        // methods for setting the colors
        void setRGB(unsigned char red, unsigned char blue, unsigned char green);
        void setHSV(unsigned char hue, unsigned char saturation, unsigned char value);

        void setRGB(double red, double green, double blue);
        void setHSV(double hue, double saturation, double value);

        // methods for retrieving the colors back
        unsigned char getRed()      { return static_cast<unsigned char>(red * 255.0); }
        unsigned char getBlue()     { return static_cast<unsigned char>(blue * 255.0); }
        unsigned char getGreen()    { return static_cast<unsigned char>(green * 255.0); }        

        unsigned char getHue()      { return static_cast<unsigned char>((hue/360.0) * 255.0); }
        unsigned char getSaturation()   { return static_cast<unsigned char>(saturation*255.0); }
        unsigned char getValue()    { return static_cast<unsigned char>(value * 255.0); }


    private:
        double red;
        double green;
        double blue;

        double hue;
        double saturation;
        double value;

        void computeHSV();
        void computeRGB();
};

#endif
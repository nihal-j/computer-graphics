#ifndef COLOR_HPP
#define COLOR_HPP

#include <algorithm>
#include <iostream>
#include <cmath>

/**
 * Color is used to store values of all channels of a color. Currently supported types of channels are RGB and HSV.
 */
class Color
{
    public:
        // default constructor
        Color();

        // Set the RGB values of the color. Accepts 0..255
        void setRGB(unsigned char red, unsigned char blue, unsigned char green);
        // set the HSV values of the color. Accepts 0..255
        void setHSV(unsigned char hue, unsigned char saturation, unsigned char value);

        // Set the RGB values of the color. Accepts 0.0 .. 1.0
        void setRGB(double red, double green, double blue);
        // Set the HSV values of the color. Accepts 0.0 .. 1.0 (Hue in range 0.0 .. 360.0)
        void setHSV(double hue, double saturation, double value);

        // methods for retrieving RGB values back as byte values
        unsigned char getRed()      { return static_cast<unsigned char>(red * 255.0); }
        unsigned char getBlue()     { return static_cast<unsigned char>(blue * 255.0); }
        unsigned char getGreen()    { return static_cast<unsigned char>(green * 255.0); }        

        // methods for retrieving HSV values back as byte values
        unsigned char getHue()          { return static_cast<unsigned char>((hue/360.0) * 255.0); }
        unsigned char getSaturation()   { return static_cast<unsigned char>(saturation*255.0); }
        unsigned char getValue()        { return static_cast<unsigned char>(value * 255.0); }


    private:
        double red;
        double green;
        double blue;

        double hue;
        double saturation;
        double value;

        // calculates HSV values from RGB values
        void computeHSV();
        // calculates RGB values from HSV values
        void computeRGB();
};

#endif
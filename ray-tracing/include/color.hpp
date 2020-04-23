#ifndef COLOR_HPP
#define COLOR_HPP

class Color
{
    public:
        /**
         * @brief Construct a new Color object
         */
        Color();

        /**
         * @brief Set RGB values of the color
         * 
         * @param red [0..255]
         * @param blue [0..255]
         * @param green [0..255]
         */
        void setRGB(unsigned char red, unsigned char blue, unsigned char green);
        /**
         * @brief Set HSV values of the color
         * 
         * @param hue [0..255]
         * @param saturation [0..255]
         * @param value [0..255]
         */
        void setHSV(unsigned char hue, unsigned char saturation, unsigned char value);

        unsigned char getRed()              { return static_cast<unsigned char>(red * 255.0); }
        unsigned char getBlue()             { return static_cast<unsigned char>(blue * 255.0); }
        unsigned char getGreen()            { return static_cast<unsigned char>(green * 255.0); }        

        unsigned char getHue()              { return static_cast<unsigned char>((hue/360.0) * 255.0); }
        unsigned char getSaturation()       { return static_cast<unsigned char>(saturation*255.0); }
        unsigned char getValue()            { return static_cast<unsigned char>(value * 255.0); }


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
#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <vector>
#include <fstream>
#include "color.hpp"

class Image
{
    public:
        Image(const int width, const int height);

        // methods to set the pixel color in an image
        int setPixel(int x, int y, unsigned char red, unsigned char blue, unsigned char green);
        int setPixel(int x, int y, Color color);

        // method to set dpi
        void setDPI(int dpi);

        // method to create a bitmap image from the channel arrays
        void toFile(std::string path);

        // method to get size of the image
        void getSize(int &x, int &y);


    private:
        std::vector<std::vector<char unsigned>> red;
        std::vector<std::vector<char unsigned>> blue;
        std::vector<std::vector<char unsigned>> green;

        int width;
        int height;

        // dots per inch
        int dpi;

};

#endif
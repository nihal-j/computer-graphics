#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <vector>
#include <fstream>
#include "color.hpp"

class Image
{
public:
    // constructor to make new image of `width`*`height`
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
    // the red channel
    std::vector<std::vector<char unsigned>> red;
    // the blue channel
    std::vector<std::vector<char unsigned>> blue;
    // the green channel
    std::vector<std::vector<char unsigned>> green;
    // width of image
    int width;
    // height of image
    int height;
    // dots per inch of the image
    int dpi;

};

#endif
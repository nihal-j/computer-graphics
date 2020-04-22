#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <vector>
#include <fstream>

class Image
{
    public:
        Image(const int width, const int height);
        int set_pixel(int x, int y, unsigned char red, unsigned char blue, unsigned char green);
        void to_file(std::string path);

    private:
        std::vector<std::vector<char unsigned>> red;
        std::vector<std::vector<char unsigned>> blue;
        std::vector<std::vector<char unsigned>> green;

        int width;
        int height;

};

#endif
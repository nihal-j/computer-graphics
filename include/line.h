#ifndef LINE_H
#define LINE_H

#include "screen.h"

class Line
{
    private:
        
        ///
        int points[3000];
        ///
        int pointCount = 0;

        /**
         * @brief Use Bresenham's Line Drawing algorithm to get the pixel values to be
         * drawn.
         * 
         * The algorithm implementation uses only integer operations, however, OpenGL requires
         * floating point values for plotting purposes. So, the pixel values are stored as
         * float numbers.
         * 
         * @param startX, startY start coordinates of the line in projection space
         * @param endX, endY end coordinates of the line in projection space
         */
        void rasterize_line(int startX, int startY, int endX, int endY);

        /**
         * @brief Utility function to store the point in `points`.
         * 
         * @param x, y point coordinates in projection space
         */
        void store_point(int x, int y);

    public:
        /**
         * @brief Construct a new Line:: Line object.
         * 
         * @param startX, startY start coordinates of the line in projection space
         * @param endX, endY end coordinates of the line in projection space
         */
        Line(int startX, int startY, int endX, int endY);

        int* get_line()   { return points; }
        int get_count()     { return pointCount; }

        /**
         * @brief 
         * 
         * @param startIdx 
         * @param count 
         */
        void print_line(int startIdx, int count);
};

#endif
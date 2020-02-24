#ifndef CIRCLE_H
#define CIRCLE_H

#include "screen.h"

class Circle
{
    private:
    
        int points[30000];
        int pointCount = 0;

        int cX, cY, radius;
        
        /**
         * @brief Run midpoint drawing algorithm on the circle and store points
         * in `points`
         * 
         */
        void scan_convert_circle();
        /**
         * @brief Utility function to store a point. Also increments `pointCount`
         * 
         * @param x, y coordinates to store
         */
        void store_point(int x, int y);
        /**
         * @brief Utility function to store a symmetric set of points. Points that are 
         * stored follow 8-way symmetry.
         * 
         * @param x, y coordinates to store
         */
        void symmetric_store_point(int x, int y);

    public:
        /**
         * @brief Construct a new Circle object.
         * 
         * @param cX, cY Center coordinates of the circle 
         * @param radius radius of the circle
         */
        Circle(int cX, int cY, int radius);
        
        /// Utility function to get points on boundary of circle (`points`)
        int* get_circle()   { return points; }
        /// Utility function to get number of points on circlee (`pointCount`)
        int get_count()     { return pointCount; }

        /**
         * @brief Utility function to print points of circle
         * 
         * @param startIdx starting point index
         * @param count number of points from `startIdx` that need to be printed
         */
        void print_circle(int startIdx, int count);
};

#endif
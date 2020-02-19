#ifndef CIRCLE_H
#define CIRCLE_H

#include "screen.h"

class Circle
{
    private:
    
        int points[30000];
        int pointCount = 0;

        int cX, cY, radius;
        
        void scan_convert_circle();
        void store_point(int x, int y);
        void symmetric_store_point(int x, int y);

    public:
        /**
         * @brief Construct a new Circle object.
         * 
         * @param cX 
         * @param cY 
         * @param radius 
         */
        Circle(int cX, int cY, int radius);
        
        /// 
        int* get_circle()   { return points; }
        /// 
        int get_count()     { return pointCount; }

        /**
         * @brief 
         * 
         * @param startIdx 
         * @param count 
         */
        void print_circle(int startIdx, int count);
};

#endif
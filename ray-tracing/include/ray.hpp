#ifndef RAY_HPP
#define RAY_HPP

#include "vector3.hpp"

class Ray
{
    public:
        Vector3 src;
        Vector3 dest;
        Vector3 direction;
        Ray(Vector3 &src, Vector3 &dst);
};

#endif
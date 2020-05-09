#ifndef RAY_HPP
#define RAY_HPP

#include "vector3.hpp"

/**
 * @brief class Ray is used to simulate a ray from `src` to `dest`.
 */
class Ray
{
public:
    /// src point of this ray
    Vector3 src;
    /// destination point of this ray
    Vector3 dest;
    /// direction vector of this ray ( = dest - src)
    Vector3 direction;

    /// constructor to setup the ray from `src` to `dst`.
    Ray(Vector3 &src, Vector3 &dst);
};

#endif
#include "ray.hpp"

Ray::Ray(Vector3 &src, Vector3 &dest)
{
    this -> src = src;
    this -> dest = dest;
    direction = dest - src;
}
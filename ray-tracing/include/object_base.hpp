#ifndef OBJECT_BASE_HPP
#define OBJECT_BASE_HPP

#include <cmath>
#include "color.hpp"
#include "ray.hpp"
#include "vector3.hpp"

class ObjectBase
{

public:
    ObjectBase();
    virtual ~ObjectBase();

    virtual bool setBaseColor(Color color);
    virtual Color getBaseColor();
    virtual bool testIntersection(const Ray castRay, Vector3 *intersection, Vector3 *normal, Color* color, double *distance);
    bool closeEnough(double d1, double d2);

};

#endif
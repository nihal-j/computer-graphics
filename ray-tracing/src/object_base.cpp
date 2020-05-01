#include "object_base.hpp"

#define EPSILON 1e-21

ObjectBase::ObjectBase()
{

}

ObjectBase::~ObjectBase()
{

}

bool ObjectBase::setBaseColor(Color color)
{
    return false;
}

Color ObjectBase::getBaseColor()
{
    Color result;
    result.setRGB(0.0, 0.0, 0.0);
    return result;
}

bool ObjectBase::testIntersection(const Ray castRay, Vector3 *intersection, Vector3 *normal, Color* color, double *distance)
{
    return false;
}

bool ObjectBase::closeEnough(double d1, double d2)
{
    return fabs(d1 - d2) < EPSILON;
}
#ifndef PLANE_HPP
#define PLANE_HPP

#include <cmath>
#include "object_base.hpp"

/**
 * @brief class Plane is used to add planes to the scene
 * @note when adding a plane, ensure that the order is such that `pt1` x `pt2` is parallel to z and so on, i.e.,
 * orientation matters.
 */

class Plane : public ObjectBase
{
public:
    /// default constructor
    Plane();
    virtual ~Plane() override;

    /// specific constructor
    Plane(Vector3 pt0, Vector3 pt1, Vector3 pt2);

    virtual bool setBaseColor(Color color) override;
    virtual Color getBaseColor() override;

    virtual bool testIntersection(const Ray castRay, Vector3 *intersection, Vector3 *normal, Color *color, double *distance) override;

private:
    /// update color of the plane
    void updateBaseColor();
    /// derive the normla equation and the direction vectors
    void updateGeometry();

    Vector3 pt0; 
    Vector3 pt1; 
    Vector3 pt2;
    Color baseColor;

    /// direction vector along plane
    Vector3 p01; 
    /// direction vector along plane
    Vector3 p02;
    /// cross product of two direction vectors along plane
    Vector3 crossp01p02;
    /// unit normal of the plane
    Vector3 planeNormal;

    double saturation;
    double value;
    double hue;
};

#endif
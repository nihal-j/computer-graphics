#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "object_base.hpp"

class Sphere : public ObjectBase
{
public:
    // default constructor and destructor
    Sphere();
    virtual ~Sphere() override;

    // constructor to custom define a sphere
    Sphere(Vector3 center, double radius);

    // methods to get and set color of the sphere
    virtual bool setBaseColor(Color color) override;
    virtual Color getBaseColor() override;

    // method to test for intersection
    virtual bool testIntersection(const Ray castRay, Vector3 *intersection, Vector3 *normal, Color *color, double *distance) override;

private:
    void updateGeometry();
    void updateBaseColor();

private:
    Vector3 center;
    double radius;
    double radius2;     // radius sqaured
    Color baseColor;

    double baseValue;
    double baseHue;
    double baseSat;

};

#endif
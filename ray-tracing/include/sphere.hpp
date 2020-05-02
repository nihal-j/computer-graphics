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
    // takes color from `baseColor` and stores into redundant variables
    void updateBaseColor();

private:
    // center of the sphere
    Vector3 center;
    // radius of the sphere
    double radius;
    // radius squared - redundant variable to avoid recomputation
    double radius2;     
    // color of the sphere
    Color baseColor;

    // representation of the color in redundant variables
    double baseValue;
    double baseHue;
    double baseSat;
};

#endif
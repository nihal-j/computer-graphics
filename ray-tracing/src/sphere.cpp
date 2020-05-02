#include "sphere.hpp"

Sphere::Sphere()
{
    // no setup for the default constructor
}

Sphere::Sphere(Vector3 center, double radius)
{
    this -> center = center;
    this -> radius = radius;
    this -> radius2 = radius*radius;
    baseColor = Color();
    baseColor.setRGB(0.0, 0.0, 0.0);
    updateBaseColor();
}

Sphere::~Sphere()
{

}

bool Sphere::setBaseColor(Color color)
{
    baseColor = color;
    updateBaseColor();
    return true;
}

Color Sphere::getBaseColor()
{
    return baseColor;
}

bool Sphere::testIntersection(const Ray castRay, Vector3 *intersection, Vector3 *normal, Color *color, double *distance)
{
    // compute the values of a, b, and c
    // a, b and c are the coeffecients of the quadratic equation obtained by solving for the intersection point of the ray and the sphere
    // equation used for the ray is in its parameteric form: x = src + (direction)*t
    // equation used for the sphere is in its standard form: |x - center|^2 = radius^2
    // solving simultaneously for t gives a quadratic equation in t whose coefficents are a, b and c.

    // unit vector along the direction of the ray
    Vector3 unitRay = castRay.direction;
    unitRay.normalize();
    // a is the sqaured magnitude of unitRay, which is always 1
    double a = 1.0;

    // calculating b
    double b = 2.0 * Vector3::dot(unitRay, castRay.src - center);

    // calculating c
    double c = Vector3::dot(castRay.src - center, castRay.src - center) - radius2;

    // if discriminant > 0, there is intersection
    double test = (b*b) - (4.0*a*c);

    if (test > 0.0)
    {
        // there is an intersection
        // solve for two values of t
        double sqrtD = sqrtf(test);
        double t1 = (-b + sqrtD) / (2*a);
        double t2 = (-b - sqrtD) / (2*a);

        // if either t1 or t2 < 0 then only part of the sphere is visible and we will not render the entire sphere
        if (t1 < 0.0 || t2 < 0.0)
            return false;
        
        // we are interested in the closest point of intersection to the camera
        Vector3 pointOfIntersection;
        if (t1 < t2)
            pointOfIntersection = castRay.src + t1*unitRay;
        else
            pointOfIntersection = castRay.src + t2*unitRay;

        // compute distance of the intersection point from the camera
        double dist = castRay.src.distanceToPoint(pointOfIntersection);

        // return these values
        *distance = dist;
        *intersection = pointOfIntersection;

        // calculate the local normal
        // for a sphere this is just a vector from center to the point
        Vector3 norm = pointOfIntersection - center;
        norm.normalize();
        *normal = norm;

        // return the color of the point
        color -> setHSV(baseHue, baseSat, baseValue);

        return true;
        
    }
    else
    {
        // there is no intersection
        return false;
    }
}

void Sphere::updateBaseColor()
{
    baseHue = baseColor.getHue();
    baseSat = baseColor.getSaturation();
    baseValue = baseColor.getValue();
}
#include "plane.hpp"

Plane::Plane()
{
    // no set up required for default constructor
}

Plane::~Plane()
{

}

Plane::Plane(Vector3 p0, Vector3 p1, Vector3 p2)
{
    pt0 = p0;
    pt1 = p1;
    pt2 = p2;
    baseColor.setRGB(1.0, 0.0, 0.0);
    updateBaseColor();
    updateGeometry();
}

bool Plane::setBaseColor(Color color)
{
    baseColor = color;
    updateBaseColor();
    return true;
}

Color Plane::getBaseColor()
{
    return baseColor;
}

void Plane::updateBaseColor()
{
    hue = baseColor.getHuef();
    value = baseColor.getValuef();
    saturation = baseColor.getSaturationf();
}

void Plane::updateGeometry()
{
    p01 = pt1 - pt0;
    p02 = pt2 - pt0;
    crossp01p02 = Vector3::cross(p01, p02);
    // std::cout << crossp01p02.x << " " << crossp01p02.y << " " << crossp01p02.z << "\n";
    planeNormal = crossp01p02.normalized();
}

bool Plane::testIntersection(const Ray castRay, Vector3 *intersection, Vector3 *normal, Color *color, double *distance)
{
    // equation of the plane:
    // normal . (x - pt0) = 0
    // equation of the ray:
    // x = src + t*ray_dir
    // On solving for t
    // t = (pt0 - src) . normal / normal . ray_dir

    Vector3 rayDirection = castRay.direction;
    rayDirection.normalize();

    double denominator = Vector3::dot(planeNormal, rayDirection);
    // std::cout << rayDirection.x << " " << rayDirection.y << " " << rayDirection.z << "\n";
    if (closeEnough(denominator, 0.0))
    {
        // ray is parallel to plane
        return false;
    }
    else
    {
        // there is an intersection

        double numerator = Vector3::dot(pt0 - castRay.src, planeNormal);
        double t = numerator / denominator;
        // std::cout << numerator << " " << denominator << "\n";

        // if t is less than 0, then intersection is behind camera
        if (t < 0.0)
            return false;
        else
        {
            Vector3 intersectionPoint = castRay.src + (t*rayDirection);
            
            // return the values to the caller
            *intersection = intersectionPoint;
            // std::cout << intersection -> x << " " << intersection -> y << " " << intersection -> z << "\n";
            *normal = planeNormal;
            *color = baseColor;
            // std::cout << hue << " " << saturation << " " << value << "\n";
            *distance = castRay.src.distanceToPoint(intersectionPoint);
            // std::cout << *distance << "\n";
            
            return true;
        }
    }
}
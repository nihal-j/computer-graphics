#ifndef OBJECT_BASE_HPP
#define OBJECT_BASE_HPP

#include <cmath>
#include "color.hpp"
#include "ray.hpp"
#include "vector3.hpp"

/**
 * @brief class ObjectBase is the parent class of all objects that are going to be rendered in the scene.
 * It should provide functionalities to set its color and get its color.
 * Also, it should provide the functionality to check if some ray cast into the scene intersects this Object.
 * Every object may have a different way of doing these things so the parent provides only a blueprint - virtual functions.
 * @note This parent class implementation will not perform any of the functionalities as they are specified here.
 */

class ObjectBase
{
public:
    /// default constructor
    ObjectBase();
    virtual ~ObjectBase();

    /// set color of the object
    virtual bool setBaseColor(Color color);
    /// get color of the object
    virtual Color getBaseColor();

    /**
     * @brief Function to check if this object intersects with `castRay`. 
     * If there is at least one intersection, then the details of only the closest intersection are returned.
     * 
     * @param castRay ray object with which intersection is being tested for
     * @param intersection reference to the closest point of intersection
     * @param normal reference to the normal calculated at the point of intersesction
     * @param color reference to the color at the closest point of intersection
     * @param distance reference to the distance from the origin of ray to the closest point of intersection
     * @return true if there is at least one intersection
     * @return false if there are no intersections
     */
    virtual bool testIntersection(const Ray castRay, Vector3 *intersection, Vector3 *normal, Color* color, double *distance);

    /// helper function to check if two double type numbers are same
    bool closeEnough(double d1, double d2);

    /// reflectivity coefficient
    double kRef;
};

#endif
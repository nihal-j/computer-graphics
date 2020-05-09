#ifndef SCENE_HPP
#define SCENE_HPP

#include <cmath>
#include <vector>
#include "vector3.hpp"
#include "object_base.hpp"
#include "light_base.hpp"
#include "image.hpp"
#include "camera.hpp"
#include "ray.hpp"

const double PI = 3.1415;

/**
 * @brief class Scene is used to simulate a screen that renders an the image of scene by coloring
 * pixels according to reflections from objects etc. 
 */
class Scene
{
public:
    /// default constructor only; no setup reqiuired
    Scene();

    /// add Camera to the scene
    bool addCamera(Camera camera);
    /// add a new Object to the scene
    bool addObject(ObjectBase* obj);
    /// add a new Light to the scene
    bool addLight(LightBase* light);

    /**
     * API to render the ray traced image into `img`. Image rendering is done by releasing rays into the image.
     * For each pixel in the `img`, a Ray is created from camera's `position` to the coordinates of the pixel and the color of that pixel is stored. This is achieved by making use of `computeColor`
     */
    bool render(Image *img);

private:
    /// single camera in the scene
    Camera camera;
    /// references to all the objects added to the scene
    std::vector<ObjectBase*> objectList;
    /// references to all the lights added to the scene
    std::vector<LightBase*> lightList;
    /// recursion limit fo reflection calculation
    int reflectionRecursionLimit;
    /// reflection recursion count
    int reflectionRecursionCount;

    /**
     * @brief API to calculate the color that is reflected using `castRay` and store the distance of the point of intersection from the camera in `dist`; makes use of `findNearestIntersection`
     */
    Color computeColor(Ray castRay, double *dist);

    /**
     * @brief Go through all the objects in `objectList` and check if `castRay` intersects the object.
     * From among all the objects with an intersection, the object that is closest to the camera is most relevant.
     * The details of this closest intersecting object is returned.
     * 
     * @param castRay `Ray` cast into the scene
     * @param intersection reference to the point of intersection
     * @param normal reference to the normal of the Object intersected calculated at the point of intersection
     * @param color color of the Object at the point of intersection
     * @param distance distance of the Camera from the point of intersection
     * @param objIndex index of the Object that has the closest intersection into `objectList`
     * @return true if there is an intersection
     * @return false if there is no intersection
     */
    bool findNearestIntersection(Ray castRay, Vector3 *intersection, Vector3 *normal, Color *color, double *distance, int *objIndex);

    void computeIllumination(const Vector3 intersection, const Vector3 normal, const int objIdx, Color *finalColor, double *intensity);

    /// for reflections
    Vector3 computeReflected(const Vector3 incident, const Vector3 normal);
};

#endif
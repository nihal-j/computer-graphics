#ifndef SCENE_HPP
#define SCENE_HPP

#include <cmath>
#include <vector>
#include "vector3.hpp"
#include "object_base.hpp"
#include "image.hpp"
#include "camera.hpp"

class Scene
{
public:
    Scene();

    bool addCamera(Camera camera);
    bool addObject(ObjectBase* obj);

    bool render(Image *img);

private:
    Camera camera;

    std::vector<ObjectBase*> objectList;

    // calculate the color that is reflected using `castRay` and the distance of the point from the camera
    Color computeColor(Ray castRay, double *dist);
    bool findNearestIntersection(Ray castRay, Vector3 *intersection, Vector3 *normal, Color *color, double *distance, int *objIndex);

};

#endif
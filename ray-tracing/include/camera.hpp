#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "vector3.hpp"
#include "ray.hpp"

/**
 * @brief class Camera simulates a camera and provides the functionality to shoot rays into the scene.
 */
class Camera
{
public:
    // point of the camera position in world coordinates
    Vector3 position;
    // point of the camera's look at in world coordinates
    Vector3 lookAt;
    // camera's up vector
    Vector3 up;
    // length from camera to screen
    double length;
    // size of a pixel
    double screenSize;

    // unit vectors defining the camera coordinate space
    Vector3 alpha;
    Vector3 beta;
    // center of the camera screen in world coordinates
    Vector3 center;
    // view vector of the camera (lookAt - position); should be stored as a normal vector
    Vector3 viewDir;

    // default constructor
    Camera();
    void setPosition(Vector3 pos);
    void setLookAt(Vector3 vec);
    void setUp(Vector3 vec);
    void setLength(double l);
    void setSize(double s);

    // camera should be able to generate a ray from its `position` to any coordinate in the scene
    // generate a ray from camera position to specified coordinates on the screen
    Ray generateRay(double screenX, double screenY);
    // calculate `alpha`, `beta`, `center` and `viewDir` from other camera properties
    void updateCamera();
};

#endif
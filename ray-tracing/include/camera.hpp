#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "vector3.hpp"
#include "ray.hpp"

class Camera
{
    public:
        Vector3 position;
        Vector3 lookAt;
        Vector3 up;
        double length;
        double screenSize;

        // unit vectors defining the camera coordinate space
        Vector3 alpha;
        Vector3 beta;
        Vector3 center;
        Vector3 viewDir;

        Camera();
        void setPosition(Vector3 pos);
        void setLookAt(Vector3 vec);
        void setUp(Vector3 vec);
        void setLength(double l);
        void setSize(double s);

        // generate a ray from camera position to specified coordinates on the screen
        Ray generateRay(double screenX, double screenY);
        // calculate all camera properties
        void updateCamera();
};

#endif
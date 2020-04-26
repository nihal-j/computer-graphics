#include "camera.hpp"

Camera::Camera()
{
    // sets default values for each of the member variables
    position = Vector3(0.0, -10.0, 0.0);
    lookAt = Vector3(0.0, 0.0, 0.0);
    up = Vector3(0.0, 0.0, 1.0);
    length = 1.0;
    screenSize = 0.25;
}

void Camera::setPosition(Vector3 pos)
{
    position = pos;
}

void Camera::setLookAt(Vector3 vec)
{
    lookAt = vec;
}

void Camera::setUp(Vector3 vec)
{
    up = vec;
}

void Camera::setLength(double l)
{
    length = l;
}

void Camera::setSize(double s)
{
    screenSize = s;
}

void Camera::updateCamera()
{
    viewDir = lookAt - position;
    viewDir.normalize();

    alpha = Vector3::cross(viewDir, up);
    alpha.normalize();
    beta = Vector3::cross(alpha, viewDir);
    beta.normalize();

    center = position + length*viewDir;
}

Ray Camera::generateRay(double screenX, double screenY)
{
    Vector3 posScreen = center + screenX*alpha;
    posScreen = posScreen + screenY*beta;

    return Ray(position, posScreen);
}
#include <iostream>
#include "scene.hpp"

Scene::Scene()
{
    // no setup necessary
}

bool Scene::addCamera(Camera camera)
{
    this -> camera = camera;
    return true;
}

bool Scene::addObject(ObjectBase* obj)
{
    objectList.push_back(obj);
    return true;
}

bool Scene::render(Image* img)
{
    int xSize, ySize;
    img -> getSize(xSize, ySize);
    Color pixelColor;
    double distance;
    // variable for sanity check
    double minDist = 1000.0;

    // normalization of coordinates to [-1, 1] needs to be done
    // formula for normalization:
    // x_normalized = pixel_size * ((x_screen*2/width) - 1)
    // y_normalized = pixel_size * ((y_screen*2/width) - 1) * aspectRatio

    float xSizef = static_cast<float>(xSize);
    float ySizef = static_cast<float>(ySize);
    float aspectRatio = ySizef / xSizef;
    // computing scaling factors
    float ss = camera.screenSize;
    float xScale = 2*ss / xSizef;
    float yScale = 2*ss / ySizef;

    for (int x = 0; x < xSize; x++)
    {
        for (int y = 0; y < ySize; y++)
        {
            float normX = (static_cast<float>(x)*xScale) - ss;
            float normY = ((static_cast<float>(y)*yScale) - ss)*aspectRatio;

            // generate a ray from the camera's position to the current x and y on the screen
            Ray castRay = camera.generateRay(normX, normY);

            // calculate the color using the ray
            pixelColor = computeColor(castRay, &distance);
            minDist = std::min(minDist, distance);

            // update the color of the pixel
            img -> setPixel(x, y, pixelColor);
        }
    }
    std::cout << "Minimum distance: " << minDist << "\n";
    return true;
}

Color Scene::computeColor(Ray castRay, double* distance)
{
    Vector3 intersection, normal;
    Color localColor, outputColor, color;
    double dist;
    int objIndex;
    bool hitFlag;

    // find the nearest object, if there is one
    hitFlag = findNearestIntersection(castRay, &intersection, &normal, &localColor, &dist, &objIndex);
    // now we know the pixel that has to be colored and the color of that pixel

    if (hitFlag)
    {
        *distance = dist;
        outputColor.setHSV(54.0, 1.0, (1 - ((dist/10.0) - 0.95)/0.05));
    }
    else
    {
        *distance = 1000.0;
        outputColor.setHSV(0.0, 0.0, 0.0);
    }
    return outputColor;
}

bool Scene::findNearestIntersection(Ray castRay, Vector3 *intersection, Vector3 *normal, Color *color, double *distance, int *objIndex)
{
    double minDist = 1000.0;
    double distance_;
    Color color_;
    Vector3 normal_, intersection_;
    bool hitFlag = false;

    // go over all the objects in `objectList`
    for (int i = 0; i < static_cast<int>(objectList.size()); i++)
    {
        if (objectList[i] -> testIntersection(castRay, &intersection_, &normal_, &color_, &distance_))
        {
            // ith object intersects with `castRay`
            hitFlag = true;
            if (distance_ < minDist)
            {
                minDist = distance_;
                *intersection = intersection_;
                *color = color_;
                *normal = normal_;
                *distance = distance_;
                *objIndex = i;
            }
        }
    }
    return hitFlag;
}
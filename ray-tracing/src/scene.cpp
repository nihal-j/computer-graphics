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

bool Scene::addLight(LightBase* light)
{
    lightList.push_back(light);
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
            // `normX` and `normY` are normalized screen coordinates
            float normX = (static_cast<float>(x)*xScale) - ss;
            float normY = ((static_cast<float>(y)*yScale) - ss)*aspectRatio;

            // generate a ray from the camera's position to the current x and y on the screen
            Ray castRay = camera.generateRay(normX, normY);

            // calculate the color using the ray
            pixelColor = computeColor(castRay, &distance);
            minDist = std::min(minDist, distance);

            // update the color of the pixel
            img -> setPixel(x, y, pixelColor);
            // std::cout << +pixelColor.getRed() << " " << +pixelColor.getBlue() << " " << +pixelColor.getGreen() << "\n";
        }
    }
    std::cout << "Minimum distance: " << minDist << "\n";
    return true;
}

Color Scene::computeColor(Ray castRay, double* distance)
{
    Vector3 intersection, normal;
    Color localColor, outputColor, color, illuminationColor;
    double dist, intensity;
    int objIndex;
    bool hitFlag;

    // find the nearest object, if there is one
    hitFlag = findNearestIntersection(castRay, &intersection, &normal, &localColor, &dist, &objIndex);
    // now we know the pixel that has to be colored and the color of that pixel

    if (hitFlag)
    {
        // call computeIllumination to calculate the lighting at this point
        computeIllumination(intersection, normal, objIndex, &illuminationColor, &intensity);
        if (intensity > 0.0)
        {
            color = localColor;
            double r = color.getRedf() * illuminationColor.getRedf();
            double g = color.getGreenf() * illuminationColor.getGreenf();
            double b = color.getBluef() * illuminationColor.getBluef();
            color.setRGB(r, g, b);
        }
        else
        {
            color.setRGB(0.0, 0.0, 0.0);
        }
        outputColor = color;
    }
    else
    {
        outputColor.setRGB(0.25, 0.25, 0.25);
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
                // std::cout << +color_.getRed() << " " << +color_.getGreen() << " " << +color_.getBlue() << "\n";
                *normal = normal_;
                *distance = distance_;
                *objIndex = i;
            }
        }
    }
    return hitFlag;
}

void Scene::computeIllumination(Vector3 intersection, Vector3 normal, const int objIdx, Color *finalColor, double *intensity)
{
    Vector3 objectPoint, objectNormal;
    Color localColor, objectColor, cumulativeColor;
    double localIntensity, cumulativeIntensity;
    double r, g, b;
    double normalLength = normal.length();
    
    cumulativeIntensity = 0.0;
    r = g = b = 0.0;

    // check if there are any lights
    if (lightList.size() < 1)
    {
        // no lights in the scene
        cumulativeColor.setRGB(1.0, 1.0, 1.0);
        cumulativeIntensity = 1.0;
    }
    else
    {
        // there are lights in the scene
        // construct a ray from this intersection point to each light source
        for (int i = 0; i < static_cast<int>(lightList.size()); i++)
        {
            // construct a ray from intersection point to the light
            // Vector3 lightDir = (lightList[i] -> getPosition() - intersection).normalized();
            // Vector3 lightDst = intersection + lightDir;
            Vector3 lightPos = lightList[i] -> getPosition();

            // construct the ray from intersection point to the light source
            // shifting origin by some amount to prevent surface acne
            Vector3 origin = intersection + normal*0.001;
            Ray lightRay(origin, lightPos);

            // compute the angle between normal and the light ray
            double cos = Vector3::dot(normal, lightRay.direction) / (normal.length()*lightRay.direction.length());
            double angle = acos(cos);
            if (angle <= PI/2.0)
            {
                // getting properties of the current light source
                localColor = lightList[i] -> getColor();
                // effective intensity at the point is I_light * cos(angle)
                localIntensity = lightList[i] -> getIntensity() * cos;

                double distanceToLight = intersection.distanceToPoint(lightPos);

                // see if there is any other object in line of sight from `intersection` to light source
                for (int j = 0; j < static_cast<int>(objectList.size()); j++)
                {
                    Vector3 inters, n;
                    Color c;
                    double d;
                    if (objectList[j] -> testIntersection(lightRay, &inters, &n, &c, &d))
                    {
                        // if the object intersects with the light ray
                        if (d < distanceToLight)
                        {
                            // and its distance is less than distance of original intersection point to the light source
                            // then there should be no illumination
                            localIntensity = 0.0;
                        }
                    }
                }
            }
            else
            {
                // light source is pointing away from the point
                localColor.setRGB(0.0, 0.0, 0.0);
                localIntensity = 0.0;
            }

            double h = localColor.getHuef();
            double s = localColor.getSaturationf();
            double v = localColor.getValuef() * localIntensity;
            localColor.setHSV(h, s, v);

            r += localColor.getRedf();
            g += localColor.getGreenf();
            b += localColor.getBluef();

            cumulativeIntensity += localIntensity;
        }

        r = fmin(r, 1.0);
        g = fmin(g, 1.0);
        b = fmin(b, 1.0);
        cumulativeColor.setRGB(r, g, b);
        cumulativeIntensity = fmin(1.0, cumulativeIntensity);
    }
    *finalColor = cumulativeColor;
    *intensity = cumulativeIntensity;
}
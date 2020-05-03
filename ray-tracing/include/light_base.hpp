#ifndef LIGHT_BASE_HPP
#define LIGHT_BASE_HPP

#include "color.hpp"
#include "vector3.hpp"

class LightBase
{
public:
    LightBase();
    virtual ~LightBase();

    // set color of light
    virtual bool setColor(Color color);
    // get color of light
    virtual Color getColor();

    // set intensity of light
    virtual bool setIntensity(double intensity);
    // get intensity of light
    virtual double getIntensity();

    // set position of light
    virtual bool setPosition(Vector3 position);
    // get position of light
    virtual Vector3 getPosition();

private:
    // color of the light source
    Color color;
    // intensity of the light source
    double intensity;
    // position of the light source
    Vector3 position;
};

#endif
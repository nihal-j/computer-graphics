#ifndef LIGHT_POINT_HPP
#define LIGHT_POINT_HPP

#include "color.hpp"
#include "vector3.hpp"
#include "light_base.hpp"

class LightPoint : public LightBase
{
public:
    LightPoint();
    virtual ~LightPoint() override;
    // specific constructor
    LightPoint(Vector3 position, Color color, double intensity);

    // set color of light
    virtual bool setColor(Color color) override;
    // get color of light
    virtual Color getColor() override;

    // set intensity of light
    virtual bool setIntensity(double intensity) override;
    // get intensity of light
    virtual double getIntensity() override;

    // set position of light
    virtual bool setPosition(Vector3 position) override;
    // get position of light
    virtual Vector3 getPosition() override;

private:
    // color of the light source
    Color color;
    // intensity of the light source
    double intensity;
    // position of the light source
    Vector3 position;
};

#endif
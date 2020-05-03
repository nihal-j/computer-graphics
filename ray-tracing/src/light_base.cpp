#include "light_base.hpp"

LightBase::LightBase()
{
    // no setup required for default constructor
}

LightBase::~LightBase()
{

}

bool LightBase::setColor(Color color)
{
    this -> color = color;
    return true;
}

Color LightBase::getColor()
{
    return color;
}

bool LightBase::setIntensity(double intensity)
{
    this -> intensity = intensity;
    return true;
}

double LightBase::getIntensity()
{
    return intensity;
}

bool LightBase::setPosition(Vector3 position)
{
    this -> position = position;
    return true;
}

Vector3 LightBase::getPosition()
{
    return position;
}
#include "light_point.hpp"

LightPoint::LightPoint()
{
    // no setup required for default constructor
}

LightPoint::~LightPoint()
{

}

LightPoint::LightPoint(Vector3 position, Color color, double intensity)
{
    this -> position = position;
    this -> color = color;
    this -> intensity = intensity;
}

bool LightPoint::setColor(Color color)
{
    this -> color = color;
    return true;
}

Color LightPoint::getColor()
{
    return color;
}

bool LightPoint::setIntensity(double intensity)
{
    this -> intensity = intensity;
    return true;
}

double LightPoint::getIntensity()
{
    return intensity;
}

bool LightPoint::setPosition(Vector3 position)
{
    this -> position = position;
    return true;
}

Vector3 LightPoint::getPosition()
{
    return position;
}
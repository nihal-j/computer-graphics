#include "vector3.hpp"

Vector3::Vector3()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector3::Vector3(double x, double y, double z)
{
    this -> x = x;
    this -> y = y;
    this -> z = z;
}

void Vector3::setX(double x)
{
    this -> x = x;
}

void Vector3::setY(double y)
{
    this -> y = y;
}

void Vector3::setZ(double z)
{
    this -> z = z;
}

double Vector3::getX() const
{
    return x;
}

double Vector3::getY() const
{
    return y;
}

double Vector3::getZ() const
{
    return z;
}

void Vector3::normalize()
{
    double norm = sqrt((x*x) + (y*y) + (z*z));
    x /= norm;
    y /= norm;
    z /= norm;
}

Vector3 Vector3::normalized()
{
    Vector3 result;
    double norm = sqrt((x*x) + (y*y) + (z*z));
    result.x = x / norm;
    result.y = y / norm;
    result.z = z / norm;
    return result; 
}

double Vector3::distanceToPoint(Vector3 &point) const
{
   double xComp = x - point.x;
   double yComp = y - point.y;
   double zComp = z - point.z;
   double dist = sqrt((xComp*xComp) + (yComp*yComp) + (zComp*zComp));
    return dist;
}

double Vector3::length()
{
    return sqrt((x*x) + (y*y) + (z*z));
}

Vector3 Vector3::operator+(const Vector3 &rhs) const
{
    Vector3 result;
    result.x = x + rhs.x;
    result.y = y + rhs.y;
    result.z = z + rhs.z;
    return result;
}

Vector3 Vector3::operator-(const Vector3 &rhs) const
{
    Vector3 result;
    result.x = x - rhs.x;
    result.y = y - rhs.y;
    result.z = z - rhs.z;
    return result;
}

Vector3 Vector3::operator-() const
{
    Vector3 result;
    result.x = -x;
    result.y = -y;
    result.z = -z;
    return result;
}

Vector3 Vector3::operator+(const double &rhs) const
{
    Vector3 result;
    result.x = x + rhs;
    result.y = y + rhs;
    result.z = z + rhs;
    return result;
}

Vector3 Vector3::operator-(const double &rhs) const
{
    Vector3 result;
    result.x = x - rhs;
    result.y = y - rhs;
    result.z = z - rhs;
    return result;
}

Vector3 Vector3::operator*(const double &rhs) const
{
    Vector3 result;
    result.x = x * rhs;
    result.y = y * rhs;
    result.z = z * rhs;
    return result;
}

Vector3 Vector3::operator/(const double &rhs) const
{
    Vector3 result;
    result.x = x / rhs;
    result.y = y / rhs;
    result.z = z / rhs;
    return result;
}

double Vector3::dot(const Vector3 &a, const Vector3 &b)
{
    double result;
    result = (a.x*b.x) + (a.y*b.y) + (a.z*b.z);
    return result;
}

Vector3 Vector3::cross(const Vector3& a, const Vector3 &b)
{
    Vector3 result;
    result.x = (a.y*b.z) - (a.z*b.y);
    result.y = (b.x*a.z) - (a.x*b.z);
    result.z = (a.x*b.y) - (a.y*b.x);
    return result;
}

Vector3 operator+(const double &lhs, const Vector3& rhs)
{
    Vector3 result;
    result.x = lhs + rhs.x;
    result.y = lhs + rhs.y;
    result.z = lhs + rhs.z;
    return result;
}

Vector3 operator-(const double &lhs, const Vector3& rhs)
{
    Vector3 result;
    result.x = lhs - rhs.x;
    result.y = lhs - rhs.y;
    result.z = lhs - rhs.z;
    return result;
}

Vector3 operator*(const double &lhs, const Vector3& rhs)
{
    Vector3 result;
    result.x = lhs * rhs.x;
    result.y = lhs * rhs.y;
    result.z = lhs * rhs.z;
    return result;
}
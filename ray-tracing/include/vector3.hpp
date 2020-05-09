#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>

/**
 * @brief class Vector3 is a library to provide all functionalities related to vector mathematics.
 */
class Vector3
{
public:
    double x;
    double y;
    double z;

    /// default constructor sets all parameters to zero
    Vector3();
    /// constructor to initialize the parameters to argument values
    Vector3(double x, double y, double z);

    /// set the values
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    /// get the values
    double getX() const;
    double getY() const;
    double getZ() const;

    /// vector operations
    /// in place normalization
    void normalize();
    /// get a normalized instance of the vectors
    Vector3 normalized();
    /// calculate distnace of some specified `point` from this vector
    double distanceToPoint(Vector3 &point) const;
    /// return norm of vector
    double length();

    /// static functions
    /// dot product of `a` and `b`
    static double dot(const Vector3 &a, const Vector3 &b);
    /// cross product of `a` and `b`
    static Vector3 cross(const Vector3 &a, const Vector3 &b);

    /// overloaded operators
    /// vector operations --- (vec1 op vec2) or (op vec1)
    Vector3 operator+(const Vector3 &rhs) const;
    Vector3 operator-(const Vector3 &rhs) const;
    Vector3 operator-() const;                         /// unary negation

    /// scalar operations --- (vec1 op scalar)
    Vector3 operator+(const double &rhs) const;
    Vector3 operator-(const double &rhs) const;
    Vector3 operator*(const double &rhs) const;
    Vector3 operator/(const double &rhs) const;

    /// scalar operations --- (scalar op vec1)
    /// declaring these as friend gives them access to the class's private members
    friend Vector3 operator+(const double &lhs, const Vector3 &rhs);
    friend Vector3 operator-(const double &lhs, const Vector3 &rhs);
    friend Vector3 operator*(const double &lhs, const Vector3 &rhs);
};

#endif
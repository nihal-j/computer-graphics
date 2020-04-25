#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>

class Vector3
{
    public:
        double x;
        double y;
        double z;

        // constructors
        Vector3();
        Vector3(double x, double y, double z);

        // set the values
        void setX(double x);
        void setY(double y);
        void setZ(double z);

        // get the values
        double getX() const;
        double getY() const;
        double getZ() const;

        // vector operations
        // in place normalization
        void normalize();
        // get a normalized instance of the vectors
        Vector3 normalized();
        double distanceToPoint(Vector3 &point) const;

        // static functions
        static double dot(const Vector3 &a, const Vector3 &b);
        static Vector3 cross(const Vector3 &a, const Vector3 &b);

        // overloaded operators
        // vector operations --- (vec1 op vec2) or (op vec1)
        Vector3 operator+(const Vector3 &rhs) const;
        Vector3 operator-(const Vector3 &rhs) const;
        Vector3 operator-() const;                         // unary negation

        // scalar operations --- (vec1 op scalar)
        Vector3 operator+(const double &rhs) const;
        Vector3 operator-(const double &rhs) const;
        Vector3 operator*(const double &rhs) const;
        Vector3 operator/(const double &rhs) const;

        // scalar operations --- (scalar op vec1)
        // declaring these as friend gives them access to the class's private members
        friend Vector3 operator+(const double &lhs, const Vector3 &rhs);
        friend Vector3 operator-(const double &lhs, const Vector3 &rhs);
        friend Vector3 operator*(const double &lhs, const Vector3 &rhs);
};

#endif
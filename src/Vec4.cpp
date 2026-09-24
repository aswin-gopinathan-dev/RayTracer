#include "../inc/Vec4.h"
#include <iostream>
#include <math.h>


Vec4::Vec4()
{
    x = 0; y = 0; z = 0; z = 0;
}

Vec4::Vec4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vec4::~Vec4()
{
}

void Vec4::print()
{
    std::cout << x << ", " << y << ", " << z << ", " << w << std::endl;
}

Point::Point(float x, float y, float z) : Vec4(x, y, z, 1.0f)
{

}

Vector::Vector(float x, float y, float z) : Vec4(x, y, z, 0.0f)
{

}

const float EPSILON = 0.00001;

bool Vector::operator == (const Vector& v) const
{
    return (fabs(x - v.x) < EPSILON && 
            fabs(y - v.y) < EPSILON && 
            fabs(z - v.z) < EPSILON && 
            fabs(w - v.w) < EPSILON);
}

bool Point::operator == (const Point& pt) const
{
    return(fabs(x - pt.x) < EPSILON && 
            fabs(y - pt.y) < EPSILON && 
            fabs(z - pt.z) < EPSILON && 
            fabs(w - pt.w) < EPSILON); 
}


Point Point::add(Vector& v)
{
    Point pt = { x + v.x, y + v.y, z + v.z};
    return pt;
}

Vector Point::sub(Point& p)
{
    Vector v = { x - p.x, y - p.y, z - p.z };
    return v;
}

Point Point::sub(Vector& v)
{
    Point pt = { x - v.x, y - v.y, z - v.z };
    return pt;
}

Vector Vector::sub(Vector& v)
{
    Vector ret = { x - v.x, y - v.y, z - v.z };
    return ret;
}

void Vector::negate()
{
    this->x *= -1; 
    this->y *= -1;
    this->z *= -1;
}

void Vector::scale(float s)
{
    this->x *= s; 
    this->y *= s;
    this->z *= s;
}

float Vector::magnitude()
{
    return sqrt(x*x + y*y + z*z);
}

void Vector::normalize()
{
    float mag = magnitude();
    this->x /= mag;
    this->y /= mag;
    this->z /= mag;
}

float Vector::dot(const Vector& v)
{
    return x * v.x + y * v.y + z * v.z;
}

Vector Vector::cross(const Vector& v)
{
    return Vector(y * v.z - z * v.y,
                  z * v.x - x * v.z,
                  x * v.y - y * v.x);
}



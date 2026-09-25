#include "../inc/Color.h"
#include <math.h>

Color::Color() : r(0.0f), g(0.0f), b(0.0f)
{
}

Color::Color(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

Color::~Color()
{
}

Color Color::operator+(const Color& c)
{
    Color color;
    color.r = r + c.r;
    color.g = g + c.g;
    color.b = b + c.b;
    return color;
}

Color Color::operator-(const Color& c)
{
    Color color;
    color.r = r - c.r;
    color.g = g - c.g;
    color.b = b - c.b;
    return color;
}

Color Color::operator*(const Color& c)
{
    Color color;
    color.r = r * c.r;
    color.g = g * c.g;
    color.b = b * c.b;
    return color;
}

Color Color::operator*(float s)
{
    Color color;
    color.r = this->r * s;
    color.g = this->g * s;
    color.b = this->b * s;
    return color;
}


const float EPSILON = 0.0001f;
bool Color::operator==(const Color& c)
{
    return (fabs(r-c.r) < EPSILON && 
            fabs(g-c.g) < EPSILON && 
            fabs(b-c.b) < EPSILON);
}

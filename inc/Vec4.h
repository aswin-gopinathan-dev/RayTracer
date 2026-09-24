#pragma once

class Vec4
{
public:
    float x, y, z, w;
    Vec4();
	Vec4(float x, float y, float z, float w);
	~Vec4();
    void print();

private:
	
};

class Vector;

class Point : public Vec4
{
public:
    Point(float x, float y, float z);
    Point add(Vector& v);
    Vector sub(Point& p);
    Point sub(Vector& v);
    bool operator == (const Point& pt) const;
};

class Vector : public Vec4
{
public:
    Vector(float x, float y, float z);
    bool operator == (const Vector& v) const;
    Vector sub(Vector& v);
    void negate();
    void scale(float s);
    float magnitude();
    void normalize();
    float dot(const Vector& v);
    Vector cross(const Vector& v);
};



#pragma once

class Color
{
public:
    float r, g, b;
	Color();
    Color(float r, float g, float b);
	~Color();

    Color operator+(const Color& c);
    Color operator-(const Color& c);
    Color operator*(const Color& c);
    Color operator*(float s);
    bool operator==(const Color& c);

private:
	
};
	

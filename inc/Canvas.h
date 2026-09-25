#pragma once
#include "Color.h"

class Canvas
{
public:
    Color* pixels;
    int width;
    int height;
	Canvas(int w, int h);
	~Canvas();
    Color GetColor(int i, int j);
    void SetPixel(int i, int j, Color color);
    void Save();

private:
	
};
	

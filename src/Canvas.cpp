#include "../inc/Canvas.h"
#include <fstream>

Canvas::Canvas(int w, int h) : width(w), height(h)
{
    pixels = new Color[width * height];
}

Canvas::~Canvas()
{
    delete[] pixels;
    pixels = nullptr;
}

Color Canvas::GetColor(int i, int j)
{
    return pixels[j*width + i];
}

void Canvas::SetPixel(int i, int j, Color color)
{
    pixels[j*width+i] = color;
}

void Canvas::Save()
{
    std::ofstream file("./build/image.ppm");
    file << "P3\n";
    file << width << " " << height <<"\n";
    file << "255\n";
    for (int i = 0; i< width; i++)
    {
        for(int j=0; j<height; j++)
        {
            Color color = pixels[j * width + i];
            file << int(color.r*255.0) << " " << int(color.g*255.0) << " " << int(color.b*255.0) << "\n";
        }
    }
    file.close();
}

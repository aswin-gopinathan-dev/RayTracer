#pragma once
#include <vector>
#include "Vec4.h"
#include <cstddef>


class Matrix
{
public:
    std::vector<std::vector<float>> m;
	Matrix(int row = 4, int col = 4);
	~Matrix();

    Matrix(std::initializer_list<std::initializer_list<float>> val);
    std::vector<float>& operator[](std::size_t row);
    bool operator==(const Matrix& m1);
    Matrix operator*(const Matrix& m1);
    Vector operator*(const Vector& v);
    Point operator*(const Point& p);    
    

private:
	
};
	

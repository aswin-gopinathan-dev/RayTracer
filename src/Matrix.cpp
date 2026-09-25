#include "../inc/Matrix.h"
#include <math.h>
#include <iostream>

Matrix::Matrix(int row, int col)
{
    m.resize(row);
    for(int i=0;i<row;i++)
    {
        m[i].resize(col);
    }
}

Matrix::~Matrix()
{

}

Matrix::Matrix(std::initializer_list<std::initializer_list<float>> val)
{
    for (const auto& row : val)
    {
        m.emplace_back(row); 
    }
}

std::vector<float>& Matrix::operator[](std::size_t row)
{
    return m[row];
}

bool Matrix::operator==(const Matrix& matrix)
{
   if(m.size() != matrix.m.size())
       return false;

   if(!m.empty() && !matrix.m.empty() && m[0].size() != matrix.m[0].size())
       return false;

   for(size_t i = 0; i < m.size(); i++)
   {
       for(size_t j = 0; j <m[i].size(); j++)
       {
           if(fabs(m[i][j] - matrix.m[i][j]) > 0.0001)
               return false;
       }
   }

   return true;
}

Matrix Matrix::operator*(const Matrix& m1)
{
    Matrix result;

    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m1.m[0].size(); j++)
        {
            result[i][j] = 0.0f;

            for (size_t k = 0; k < m[0].size(); k++)
            {
                result[i][j] += m[i][k] * m1.m[k][j];
            }
        }
    }

    return result;
}

Vector Matrix::operator*(const Vector& v)
{
    std::vector<float> values;
    values.resize(m.size());

    std::vector<float> input(4);
    input[0] = v.x;
    input[1] = v.y;
    input[2] = v.z;
    input[3] = v.w;

    Vector result {0, 0, 0};
    
    for (size_t i = 0; i < m.size(); i++)
    {
        values[i] = 0.0f;
        for (size_t j = 0; j < m[i].size(); j++)
        {
            values[i] += m[i][j] * input[j];
        }
    }

    result.x = values[0];
    result.y = values[1];
    result.z = values[2];
    result.w = values[3];

    return result;
}

Point Matrix::operator*(const Point& v)
{
    std::vector<float> values;
    values.resize(m.size());

    std::vector<float> input(4);
    input[0] = v.x;
    input[1] = v.y;
    input[2] = v.z;
    input[3] = v.w;

    Point result {0, 0, 0};
    
    for (size_t i = 0; i < m.size(); i++)
    {
        values[i] = 0.0f;
        for (size_t j = 0; j < m[i].size(); j++)
        {
            values[i] += m[i][j] * input[j];
        }
    }

    result.x = values[0];
    result.y = values[1];
    result.z = values[2];
    result.w = values[3];

    return result;
}

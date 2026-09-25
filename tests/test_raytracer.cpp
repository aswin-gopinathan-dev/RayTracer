#include <gtest/gtest.h>
#include "../inc/Vec4.h"
#include "../inc/Color.h"
#include "../inc/Canvas.h"
#include "../inc/Matrix.h"

TEST(MathTest, Create_Vector_Point)
{
    Point pt = {4.0f, 3.0f, -4.0f};
    Vector vec = {-4.0f, -3.0f, 4.0f};
    pt.print();
    vec.print();
    ASSERT_EQ(pt.w, 1.0f);
    ASSERT_EQ(vec.w, 0.0f);
}

TEST(MathTest, Add_Point_Vector)
{
    Point pt = {3.0f, -2.0f, 5.0f};
    Vector vec = {-2.0f, 3.0f, 1.0f};
    Point exp_result = {1.0f, 1.0f, 6.0f};
    Point calc_result = pt.add(vec);
    ASSERT_EQ((calc_result == exp_result), true);
}

TEST(MathTest, Subtract_Points)
{
    Point pt1 = {3.0f, 2.0f, 1.0f};
    Point pt2 = {5.0f, 6.0f, 7.0f};
    Vector exp_result = {-2.0f, -4.0f, -6.0f};
    Vector calc_result = pt1.sub(pt2);
    ASSERT_EQ((calc_result == exp_result), true);
}

TEST(MathTest, Subtract_Vector_From_Point)
{
    Point pt = {3.0f, 2.0f, 1.0f};
    Vector v = {5.0f, 6.0f, 7.0f};
    Point exp_result = {-2.0f, -4.0f, -6.0f};
    Point calc_result = pt.sub(v);
    ASSERT_EQ((calc_result == exp_result), true);
}

TEST(MathTest, Subtract_Vectors)
{
    Vector v1 = {3.0f, 2.0f, 1.0f};
    Vector v2 = {5.0f, 6.0f, 7.0f};
    Vector exp_result = {-2.0f, -4.0f, -6.0f};
    Vector calc_result = v1.sub(v2);
    ASSERT_EQ((calc_result == exp_result), true);
}

TEST(MathTest, Vector_Negate)
{
    Vector v = {3.0f, 2.0f, 1.0f};
    Vector exp_result = {-3.0f, -2.0f, -1.0f};
    v.negate();
    ASSERT_EQ((v == exp_result), true);
}

TEST(MathTest, Vector_Scale)
{
    Vector v = {3.0f, 2.0f, 1.0f};
    Vector exp_result = {6.0f, 4.0f, 2.0f};
    v.scale(2.0f);
    ASSERT_EQ((v == exp_result), true);
}

TEST(MathTest, Vector_Magnitude)
{
    Vector v = {3.0f, 0.0f, 4.0f};
    float exp_result = 5.0f;
    ASSERT_EQ((v.magnitude() == exp_result), true);
}

TEST(MathTest, Vector_Normalize)
{
    Vector v = {3.0f, 0.0f, 4.0f};
    Vector exp_result = {3.0f/5, 0.0f, 4.0f/5};
    v.normalize();
    ASSERT_EQ((v == exp_result), true);
}

TEST(MathTest, Vector_DotProduct)
{
    Vector a = {1.0f, 2.0f, 3.0f};
    Vector b = {2.0f, 3.0f, 4.0f};
    float exp_result = 20.0f;
    ASSERT_EQ((a.dot(b) == exp_result), true);
}

TEST(MathTest, Vector_CrossProduct)
{
    Vector a = {1.0f, 2.0f, 3.0f};
    Vector b = {2.0f, 3.0f, 4.0f};
    Vector exp_result = {-1.0f, 2.0f, -1.0f};
    Vector c = a.cross(b);
    ASSERT_EQ((c == exp_result), true);
}

TEST(ColorTest, CreateColor)
{
    Color c = {0.5, 0.4, 1.0};
    float r = 0.5, g = 0.4, b = 1.0;
    ASSERT_EQ(c.r, r);
    ASSERT_EQ(c.g, g);
    ASSERT_EQ(c.b, b);
}

TEST(ColorTest, Add_Colors)
{
    Color c1 = {0.9, 0.6, 0.75};
    Color c2 = {0.7, 0.1, 0.25};
    Color result = {1.6, 0.7, 1.0};
    ASSERT_EQ(((c1 + c2) == result), true);
}

TEST(ColorTest, Subrtract_Colors)
{
    Color c1 = {0.9, 0.6, 0.75};
    Color c2 = {0.7, 0.1, 0.25};
    Color result = {0.2, 0.5, 0.5};
    ASSERT_EQ(((c1 - c2) == result), true);
}

TEST(ColorTest, Multiply_Colors)
{
    Color c1 = {1, 0.2, 0.4};
    Color c2 = {0.9, 1, 0.1};
    Color result = {0.9, 0.2, 0.04};
    ASSERT_EQ(((c1 * c2) == result), true);
}

TEST(ColorTest, Scale_Color)
{
    Color c = {0.2, 0.3, 0.4};
    float scale = 2;
    Color result = {0.4, 0.6, 0.8};
    ASSERT_EQ(((c * scale) == result), true);
}

TEST(CanvasTest, CreateBlackCanvas)
{
    int width = 1024, height = 768;
    Canvas c(width, height);
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            Color color = c.GetColor(i, j);
            ASSERT_EQ(color.r, 0.0f);
            ASSERT_EQ(color.g, 0.0f);
            ASSERT_EQ(color.b, 0.0f);
        }
    }
}

TEST(CanvasTest, Canvas_Read_Write_Color)
{
    int width = 1024, height = 768;
    Canvas c(width, height);
    Color c1(1.0, 0.2, 0.4);
    c.SetPixel(100, 100, c1);
    Color c2 = c.GetColor(100, 100);
    ASSERT_EQ((c1 == c2), true);
}

TEST(CanvasTest, Canvas_Save)
{
    int width = 1024, height = 768;
    Canvas c(width, height);
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            c.SetPixel(i, j, Color(0, 0, 1.0));
        }
    }
    c.Save();
}

TEST(MatrixTest, Create_Matrix)
{
    Matrix m1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    ASSERT_EQ((m1.m[0][3] == 4 && m1.m[2][2] == 11), true);
    Matrix m2 = {{1, 2}, {3, 4}};
    ASSERT_EQ((m2.m[0][1] == 2 && m2.m[1][0] == 3), true);
    Matrix m3 = {{1, 2, 3}, {4, 5, 6}, {8, 9, 10}};
    ASSERT_EQ((m3.m[0][2] == 3 && m3.m[2][2] == 10), true);
}

TEST(MatrixTest, Compare_Matrices)
{
    Matrix m1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Matrix m2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};    
    ASSERT_EQ((m1 == m2), true);

    Matrix m3 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Matrix m4 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 1}};
    ASSERT_EQ((m3 == m4), false);
}

TEST(MatrixTest, Multiply_Matrices)
{
    Matrix m1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
    Matrix m2 = {{-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}};    
    Matrix exp_result = {{20, 22, 50, 48}, {44, 54, 114, 108}, 
                        {40, 58, 110, 102}, {16, 26, 46, 42}};
    Matrix calc_result = m1 * m2;
    ASSERT_EQ((exp_result == calc_result), true);
}

TEST(MatrixTest, Multiply_Matrix_Vector)
{
    Matrix m = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
    Vector v = {1, 2, 3};
    Vector exp_result = {14, 22, 32};
    Vector calc_result = m * v;
    ASSERT_EQ((exp_result == calc_result), true);
}

TEST(MatrixTest, Multiply_Matrix_Point)
{
    Matrix m = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
    Point v = {1, 2, 3};
    Point exp_result = {18, 24, 33};
    Point calc_result = m * v;
    ASSERT_EQ((exp_result == calc_result), true);
}


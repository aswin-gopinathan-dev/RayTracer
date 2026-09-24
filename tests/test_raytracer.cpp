#include <gtest/gtest.h>
#include "../inc/Vec4.h"

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

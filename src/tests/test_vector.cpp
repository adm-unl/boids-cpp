/* test_vector.cpp
 *
 * unit tests for Vector class.
 *
 */

#include "vector.h"

#include <gtest/gtest.h>

class VectorTest : public testing::Test
{
protected:
    VectorTest()
    {
    }

    };

TEST(VectorTest, ConstructsCorrectly)
{
    Vector v{3.0, 4.0};
    EXPECT_DOUBLE_EQ( v.get_x(), 3.0 );
    EXPECT_DOUBLE_EQ( v.get_y(), 4.0 );
}

TEST(VectorTest, CalculatesMagnitude)
{
    Vector v{3.0, 4.0};
    EXPECT_DOUBLE_EQ( v.magnitude(), 5.0 );
}

TEST(VectorTest, NormaliseProducesUnitVector)
{
    Vector v1{3.0, 4.0};
    Vector v2{ v1.normalised() };

    EXPECT_DOUBLE_EQ(v2.magnitude(), 1.0);
    EXPECT_DOUBLE_EQ(v1.direction(), v2.direction());
}

TEST(VectorTest, AddsVectorCorrectly)
{
    Vector v1{ 3.0, 4.0 };
    Vector v2{ 1.0, 2.0 };

    Vector v3{ v1 + v2 };

    std::cout << "\n\n\nv3 x " << v3.get_x() << ", v3 y " << v3.get_y();

    EXPECT_DOUBLE_EQ( v3.get_x(), 4.0 );
    EXPECT_DOUBLE_EQ( v3.get_y(), 6.0 );
}

TEST(VectorTest, SubsVectorCorrectly)
{
    Vector v1{ 3.0, 4.0 };
    Vector v2{ 1.0, 2.0 };

    Vector v3{ v1 - v2 };

    EXPECT_DOUBLE_EQ( v3.get_x(), 2.0 );
    EXPECT_DOUBLE_EQ( v3.get_y(), 2.0 );
}

TEST(VectorTest, MultScalarCorrectly)
{
    Vector v{ 3.0, 4.0 };
    double scalar{ 2.0 };
    Vector res{ v * scalar };

    EXPECT_DOUBLE_EQ( res.get_x(), 6.0 );
    EXPECT_DOUBLE_EQ( res.get_y(), 8.0 );
}

TEST(VectorTest, DivScalarCorrectly)
{
    Vector v{ 3.0, 4.0 };
    double scalar{ 2.0 };
    Vector res{ v / scalar };

    EXPECT_DOUBLE_EQ( res.get_x(), 1.5 );
    EXPECT_DOUBLE_EQ( res.get_y(), 2.0 );
}

TEST(VectorTest, CalculatesDirectionCorrectly)
{
    Vector up{ 0.0, 1.0 };
    Vector right{ 1.0, 0.0 };
    Vector down{ 0.0, -1.0 };
    Vector left{ -1.0, 0.0 };

    EXPECT_DOUBLE_EQ( up.direction(), 0.0 );
    EXPECT_DOUBLE_EQ( right.direction(), 90.0 );
    EXPECT_DOUBLE_EQ( down.direction(), 180.0 );
    EXPECT_DOUBLE_EQ( left.direction(), -90.0 );
}

TEST(VectorTest, CorretlyLimitsMagnitude)
{
    Vector v{10, 0};
    Vector limited{ v.limited(2.0f) };

    EXPECT_DOUBLE_EQ( limited.magnitude(), 2.0 );
}

TEST(VectorTest, NormalisingZeroVector)
{
    Vector v{0, 0};
    Vector n{ v.normalised() };

    EXPECT_DOUBLE_EQ( n.magnitude(), 0.0 );
}



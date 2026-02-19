/* test_utility.cpp
 *
 * tests functions defined in Utility namespace.
 *
 */

#include "utility.h"

#include <gtest/gtest.h>

TEST(UtilityTest, CheckAngleDiffWrapsCorrectly)
{
    double a1{ Utility::angle_diff( 179, -179 ) };
    double a2{ Utility::angle_diff( 190, 10 ) };
    double a3{ Utility::angle_diff( 10, 190 ) };
    double a4{ Utility::angle_diff( 350, 10 ) };

    EXPECT_DOUBLE_EQ( a1, 2.0 );
    EXPECT_DOUBLE_EQ( a2, 180.0 );
    EXPECT_DOUBLE_EQ( a3, 180.0 );
    EXPECT_DOUBLE_EQ( a4, 20.0 );
}

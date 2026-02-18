/* test_boid.cpp
 *
 * units tests for Boid class.
 *
 */

#include "boid.h"

#include <gtest/gtest.h>

TEST(BoidTest, IsStationaryOriginByDefault)
{
    Boid b{};
    EXPECT_EQ(b.get_position(), (Vector{0, 0}));
    EXPECT_EQ(b.get_velocity(), (Vector{0, 0}));
}


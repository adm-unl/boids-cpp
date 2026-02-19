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

TEST(BoidTest, ConstructCorrectly)
{
    Vector position{ 2.0, 2.0 };
    Vector velocity{ 1.0, 0.0 };
    Boid b{ position, velocity };

    EXPECT_EQ( b.get_position(), position );
    EXPECT_EQ( b.get_velocity(), velocity );
}

TEST(BoidTest, SetsCorrectly)
{
    Boid b{};
    Vector position{ 2.0, 2.0 };
    Vector velocity{ 1.0, 0.0 };
    b.set_position(position);
    b.set_velocity(velocity);

    EXPECT_EQ( b.get_position(), position );
    EXPECT_EQ( b.get_velocity(), velocity );
}

TEST(BoidTest, CalculatesDistanceCorrectly)
{
    Boid b1{};
    Boid b2{};
    b2.set_position( Vector{5, 0} );

    EXPECT_DOUBLE_EQ( b1.distance_to(b2), 5.0 );
}

TEST(BoidTest, FindsNeighboursCorrectly)
{
    Boid b{ Vector{0, 0}, Vector{0, 1} };
    Boid b_close{ Vector{1, 0}, Vector{1, 1} };
    Boid b_far{ Vector{10, 0}, Vector{2, 1} };

    std::vector<Boid> all_boids{ b_close, b_far };
    auto neighbours{ b.find_neighbours(all_boids, 3.0, 240.0f) };

    ASSERT_EQ( neighbours.size(), 1 );
    EXPECT_EQ( neighbours[0].get_position(), (Vector{1, 0}) );
}

TEST(RulesTest, SeparationReturnsAwayVector)
{
    Boid b{};
    Boid neighbour{ Vector{1, 0}, Vector{0, 0} };
    BoidConfig config{};
    config.separation_radius = 2.0;

    std::vector<Boid> neighbours{ neighbour };
    Vector res{ Rules::seperation(b, neighbours, config) };

    EXPECT_LT( res.get_x(), 0.0 ); // should push away along x-axis
    EXPECT_DOUBLE_EQ( res.get_y(), 0.0 );
}

TEST(RulesTest, AlignmentMatchesAvgVelocity)
{
    Boid b{};
    Boid n1{ Vector{1, 0}, Vector{1, 0} };
    Boid n2{ Vector{-1, 0}, Vector{1, 0} };
    BoidConfig config{};
    config.separation_radius = 2.0;
    config.alignment_weight = 1.0;

    std::vector<Boid> neighbours{ n1, n2 };
    Vector res{ Rules::alignment(b, neighbours, config) };

    EXPECT_DOUBLE_EQ( res.get_x(), 1.0 ); // avg of neighbours
    EXPECT_DOUBLE_EQ( res.get_y(), 0.0 );
}

TEST(RulesTest, CohesionPointsTowardsAvgPosition)
{
    Boid b{};
    Boid n1{ Vector{2, 0}, Vector{0, 0} };
    Boid n2{ Vector{0, 2}, Vector{0, 0} };
    BoidConfig config{};
    config.separation_radius = 2.0;
    config.cohesion_weight = 1.0;

    std::vector<Boid> neighbours{ n1, n2 };
    Vector res{ Rules::cohesion(b, neighbours, config) };

    EXPECT_DOUBLE_EQ( res.get_x(), 1.0 ); // avg position is (1, 1)
    EXPECT_DOUBLE_EQ( res.get_y(), 1.0 );
}


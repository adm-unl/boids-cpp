/* rules.cpp
 *
 * implements the rules for boid behaviour.
 *
 */

#include "boid.h"

Vector Rules::seperation(
        const Boid& boid,
        const std::vector<Boid>& neighbours,
        const BoidConfig& config)
{
    Vector res{};

    for (const auto& other : neighbours)
    {
        double d{ boid.distance_to(other) };
        if (d > 0 && d < config.separation_radius)
        {
            res = res - (other.get_position() - boid.get_position());
        }
    }
    return res * config.separation_weight;
}

Vector Rules::alignment(
        const Boid& boid,
        const std::vector<Boid>& neighbours,
        const BoidConfig& config)
{
    Vector res{};

    for (const auto& other : neighbours)
    {
        res = res + other.get_velocity();
    }
    res = res / neighbours.size();

    return (res - boid.get_velocity()) / config.alignment_weight;
}

Vector Rules::cohesion(
        const Boid& boid,
        const std::vector<Boid>& neighbours,
        const BoidConfig& config)
{
    Vector res{};

    for (const auto& other : neighbours)
    {
        res = res + other.get_position();
    }
    res = res / neighbours.size();

    return (res - boid.get_position()) / config.cohesion_weight;
}



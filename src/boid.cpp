/* boid.cpp
 *
 * implements members of Boid class.
 *
 */

#include "boid.h"
#include "utility.h"

#include <cmath>

Boid::Boid(const Vector& position, const Vector& velocity) :
    m_position{ position },
    m_velocity{ velocity }
{
}

double Boid::distance_to(const Boid& other) const
{
    return (m_position - other.m_position).magnitude();
}

std::vector<Boid> Boid::find_neighbours(const std::vector<Boid>& all_boids, double radius, float fov)
{
    std::vector<Boid> neighbours{};
    for (const auto& other : all_boids)
    {
        if (this == &other)
            continue;

        Vector boid_to_other{ other.get_position() - get_position() };
        double direction_diff{ Utility::angle_diff(get_velocity().direction(), boid_to_other.direction()) };
        if (distance_to(other) < radius && direction_diff < fov / 2)
            neighbours.push_back(other);
    }
    return neighbours;
}

Boid Boid::random(double x_max, double y_max, double v_limit)
{
    return { Utility::get_rand_position(x_max, y_max), Utility::get_rand_velocity(v_limit) };
}

std::ostream& operator<<(std::ostream& out, const Boid& b)
{
    out << "Boid(position=" << b.m_position << ", velocity=" << b.m_velocity
        << ')';
    return out;
}


/* world.cpp
 *
 * implements member functions of World class.
 *
 */

#include "world.h"

World::World(int num_boids, int rows, int cols) :
    m_rows{ rows },
    m_cols{ cols }
{
    m_boids.resize(num_boids);
    for (std::size_t i{0}; i < m_boids.size(); ++i)
        m_boids[i] = Boid::random(m_cols, m_rows, m_config.max_speed);
}

void World::update()
{
    std::vector<Boid> new_boids = m_boids;
    for (std::size_t i{0}; i < m_boids.size(); ++i)
    {
        Boid& old_b{ m_boids[i] };
        Boid& new_b{ new_boids[i] };
        std::vector<Boid> neighbours{ old_b.find_neighbours(m_boids, m_config.perception_radius, m_config.field_of_view) };

        Vector velocity{old_b.get_velocity()};
        if (!neighbours.empty())
        {
            Vector v1{ Rules::seperation(old_b, neighbours, m_config) };
            Vector v2{ Rules::alignment(old_b, neighbours, m_config) };
            Vector v3{ Rules::cohesion(old_b, neighbours, m_config) };
            velocity = (velocity + v1 + v2 + v3).limited(m_config.max_speed);
        }
        Vector position{ wrap_position(old_b.get_position() + velocity) };

        new_b.set_position(position);
        new_b.set_velocity(velocity);
    }
    m_boids = new_boids;
}

std::ostream& operator<<(std::ostream& out, const World& w)
{
    out << "\033[2j\033[H"; // clear console and move cursor top left

    std::vector<char> grid(w.m_rows * w.m_cols, ' ');
    for (const auto& boid : w.m_boids)
    {
        Vector p{ boid.get_position() };
        int x_idx{ static_cast<int>(p.get_x()) };
        int y_idx{ static_cast<int>(p.get_y()) };
        char& pos{ grid[y_idx * w.m_cols + x_idx] };

        double x_v{ boid.get_velocity().get_x() };
        double y_v{ boid.get_velocity().get_y() };

        if (std::abs(x_v) > std::abs(y_v))
            pos = (x_v > 0) ? '>' : '<';
        else
            pos = (y_v > 0) ? 'v' : '^';
    }

    for (int r{0}; r < w.m_rows; ++r)
    {
        for (int c{0}; c < w.m_cols; ++c)
        {
            out << ' ' << grid[r * w.m_cols + c] << ' ';
        }
        out << '\n';
    }
    return out;
}

Vector World::wrap_position(Vector position)
{
    double x = std::fmod(position.get_x(), m_cols);
    x = (x < 0 ? x + m_cols : x);

    double y = std::fmod(position.get_y(), m_rows);
    y = (y < 0 ? y + m_rows : y);

    return { x, y };
}


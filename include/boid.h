/* boid.h
 *
 * implements Boid class.
 *
 */

#ifndef BOID_H
#define BOID_H

#include "vector.h"
#include "config.h"

#include <vector>

class Boid;

namespace Rules
{
    Vector seperation(
            const Boid& boid,
            const std::vector<Boid>& neighbours,
            const BoidConfig& config);

    Vector alignment(
            const Boid& boid,
            const std::vector<Boid>& neighbours,
            const BoidConfig& config);

    Vector cohesion(
            const Boid& boid,
            const std::vector<Boid>& neighbours,
            const BoidConfig& config);
};

class Boid
{
public:
    Boid() = default;

    Boid(const Vector& position, const Vector& velocity);

    const Vector& get_position() const { return m_position; }
    void set_position(const Vector& v) { m_position = v; }

    const Vector& get_velocity() const { return m_velocity; }
    void set_velocity(const Vector& v) { m_velocity = v; }

    double distance_to(const Boid& other) const;

    std::vector<Boid> find_neighbours(const std::vector<Boid>& all_boids, double radius, float fov);

    friend std::ostream& operator<<(std::ostream& out, const Boid& b);

    static Boid random(double x_max, double y_max, double v_limit);

private:
    Vector m_position{};
    Vector m_velocity{};
};


#endif

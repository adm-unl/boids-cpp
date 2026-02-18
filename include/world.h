/* world.h
 *
 * implements boid world class.
 *
 */

#ifndef WORLD_H
#define WORLD_H

#include "boid.h"
#include "config.h"
#include "utility.h"

#include <vector>
#include <algorithm>

class World
{
public:
    World(int num_boids, int rows, int cols);

    void update();

    friend std::ostream& operator<<(std::ostream& out, const World& w);

private:
    int m_rows{};
    int m_cols{};
    std::vector<Boid> m_boids{};
    BoidConfig m_config{};

    Vector wrap_position(Vector position);

};

#endif

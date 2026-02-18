/* utility.h
 *
 * useful functions.
 *
 */

#include "vector.h"
#include "boid.h"

#include <utility>

namespace Utility
{
    std::pair<double, double> get_rand_xy_norm();

    Vector get_rand_position(double x_max, double y_max);

    Vector get_rand_velocity(double v_limit);

    double angle_diff(double target, double source);
};

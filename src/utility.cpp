/* utility.cpp
 *
 * implements useful functions.
 *
 */

#include "utility.h"
#include "random.h"

#include <cmath>

std::pair<double, double> Utility::get_rand_xy_norm()
{
    static int max_int{ std::numeric_limits<int>::max() };
    double x_norm{ Random::get(0, max_int) / static_cast<double>(max_int) };
    double y_norm{ Random::get(0, max_int) / static_cast<double>(max_int) };
    return { x_norm, y_norm };
}

Vector Utility::get_rand_position(double x_max, double y_max)
{
    std::pair rand_xy{ Utility::get_rand_xy_norm() };
    return { rand_xy.first * x_max, rand_xy.second * y_max };
}

Vector Utility::get_rand_velocity(double v_limit)
{
    std::pair rand_xy{ Utility::get_rand_xy_norm() };
    return { 2 * v_limit * rand_xy.first - v_limit, 2 * v_limit * rand_xy.second - v_limit};
}

double Utility::angle_diff(double target, double source)
{
    double diff{ target - source };
    diff -= diff > 180 ? 360 : 0;
    diff += diff < -180 ? 360 : 0;
    return std::abs(diff);
}


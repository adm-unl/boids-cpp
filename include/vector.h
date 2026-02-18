/* vector.h
 *
 * implements vector class.
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include <limits>


class Vector
{
public:
    Vector() = default;

    Vector(double x, double y) :
        m_x{ x }, m_y{ y }
    {
    }

    double get_x() const { return m_x; }
    double get_y() const { return m_y; }

    double magnitude() const { return std::sqrt(m_x * m_x + m_y * m_y); }

    Vector normalised() const
    {
        double mag{ magnitude() };
        if (mag == 0)
            return *this;
        return *this / mag;
    }

    Vector limited(float max) const
    {
        if (magnitude() > max)
            return normalised() * max;
        return *this;
    }

    double direction() const // returns relative to y-axis in range [-180, 180]
    {
        return std::atan2(m_x, m_y) * 180.0 / M_PI;
    }

    Vector operator+(const Vector& other) const
    {
        return { m_x + other.m_x, m_y + other.m_y };
    }

    Vector operator-(const Vector& other) const
    {
        return { m_x - other.m_x, m_y - other.m_y };
    }

    Vector operator/(double scalar) const
    {
        return { m_x / scalar, m_y / scalar };
    }

    Vector operator*(double scalar) const
    {
        return { m_x * scalar, m_y * scalar };
    }

    bool operator==(const Vector& other) const
    {
        return m_x == other.m_x && m_y == other.m_y;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v)
    {
        out << "Vector(" << v.m_x << ", " << v.m_y << ')';
        return out;
    }

private:
    double m_x{};
    double m_y{};

};

#endif

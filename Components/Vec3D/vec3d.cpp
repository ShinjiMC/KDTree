#include <cmath>
#include "vec3d.hpp"

Vec3D::Vec3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

Vec3D::Vec3D() : x(0.0), y(0.0), z(0.0) {}

double Vec3D::getX() const { return x; }
double Vec3D::getY() const { return y; }
double Vec3D::getZ() const { return z; }
double Vec3D::getCord(int cord) const
{
    switch (cord)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    default:
        return 0.0;
    }
}
double Vec3D::distance(const Vec3D &other) const
{
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
}

Vec3D Vec3D::operator+(const Vec3D &other) const
{
    return Vec3D(x + other.x, y + other.y, z + other.z);
}

Vec3D Vec3D::operator-(const Vec3D &other) const
{
    return Vec3D(x - other.x, y - other.y, z - other.z);
}

Vec3D Vec3D::operator*(double scalar) const
{
    return Vec3D(x * scalar, y * scalar, z * scalar);
}

Vec3D Vec3D::operator/(double scalar) const
{
    if (scalar != 0)
        return Vec3D(x / scalar, y / scalar, z / scalar);
    return Vec3D();
}

bool Vec3D::operator==(const Vec3D &other) const
{
    return x == other.x && y == other.y && z == other.z;
}

bool Vec3D::operator!=(const Vec3D &other) const
{
    return !(*this == other);
}

bool Vec3D::operator<(const Vec3D &other) const
{
    if (x != other.x)
        return x < other.x;
    if (y != other.y)
        return y < other.y;
    return z < other.z;
}
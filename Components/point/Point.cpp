#include "Point.hpp"

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point::Point()
{
    x = 0.0;
    y = 0.0;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::print()
{
    std::cout << "(" << x << ", " << y << ")";
}

bool Point::operator==(const Point &p)
{
    return (x == p.x && y == p.y);
}

bool Point::operator!=(const Point &p)
{
    return (x != p.x || y != p.y);
}

bool Point::operator<(const Point &p)
{
    return (x < p.x || (x == p.x && y < p.y));
}

bool Point::operator>(const Point &p)
{
    return (x > p.x || (x == p.x && y > p.y));
}

bool Point::operator<=(const Point &p)
{
    return (x <= p.x || (x == p.x && y <= p.y));
}

bool Point::operator>=(const Point &p)
{
    return (x >= p.x || (x == p.x && y >= p.y));
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Point &p)
{
    is >> p.x >> p.y;
    return is;
}
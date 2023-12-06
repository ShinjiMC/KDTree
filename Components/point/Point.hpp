#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point
{
private:
    double x, y;

public:
    Point(double x, double y);
    Point();
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
    void print();
    bool operator==(const Point &p);
    bool operator!=(const Point &p);
    bool operator<(const Point &p);
    bool operator>(const Point &p);
    bool operator<=(const Point &p);
    bool operator>=(const Point &p);
    friend std::ostream &operator<<(std::ostream &os, const Point &p);
    friend std::istream &operator>>(std::istream &is, Point &p);
};

#endif // POINT_HPP
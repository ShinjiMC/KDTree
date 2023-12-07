#ifndef DIRECT_HPP
#define DIRECT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "../Vec3D/vec3d.hpp"

class Direct
{
private:
    std::vector<Vec3D> points;

public:
    Direct() {}
    Direct(std::vector<Vec3D> points) : points(points) {}
    ~Direct() = default;
    void insert(Vec3D data) { points.push_back(data); }
    void print();
    bool search(Vec3D data);
    void clear() { points.clear(); }
    std::vector<Vec3D> KNN(Vec3D data, int points);
};
#endif // DIRECT_HPP
#include "direct.hpp"
#include <map>

void Direct::print()
{
    for (const auto &c : points)
        std::cout << "(" << c.getX() << ", " << c.getY() << ", " << c.getZ() << ")" << std::endl;
}

bool Direct::search(Vec3D data)
{
    for (const auto &c : points)
        if (c == data)
            return true;
    return false;
}

std::vector<Vec3D> Direct::KNN(Vec3D data, int cantPoints)
{
    std::multimap<double, Vec3D> distanceMap;
    for (const auto &c : this->points)
    {
        double dist = c.distance(data);
        distanceMap.insert(std::make_pair(dist, c));
    }
    std::vector<Vec3D> neighbours;
    for (const auto &pair : distanceMap)
    {
        if (neighbours.size() >= cantPoints)
            break;
        neighbours.push_back(pair.second);
    }
    return neighbours;
}

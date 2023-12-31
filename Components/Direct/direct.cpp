#include "direct.hpp"
#include <set>

struct ComparePairs
{
    bool operator()(const std::pair<double, Vec3D> &a, const std::pair<double, Vec3D> &b) const
    {
        return a.first < b.first;
    }
};

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
    std::set<std::pair<double, Vec3D>, ComparePairs> closestPoints;
    for (const auto &c : this->points)
    {
        double dist = c.distance(data); // Cálculo euclidiano
        if (closestPoints.size() < static_cast<size_t>(cantPoints))
            closestPoints.emplace(dist, c);
        else
        {
            if (dist < closestPoints.rbegin()->first)
            {
                closestPoints.erase(std::prev(closestPoints.end()));
                closestPoints.emplace(dist, c);
            }
        }
    }

    std::vector<Vec3D> neighbours;
    neighbours.reserve(cantPoints);
    for (const auto &pair : closestPoints)
        neighbours.push_back(pair.second);
    return neighbours;
}

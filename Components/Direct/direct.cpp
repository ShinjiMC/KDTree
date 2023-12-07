#include "direct.hpp"
#include <algorithm>
#include <cmath>
#include <queue>

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

std::vector<Vec3D> Direct::KNN(Vec3D data, int points)
{
    std::vector<Vec3D> neighbours;
    std::priority_queue<std::pair<double, Vec3D>> max_heap;
    /*for (const auto &c : this->points)
    {
        double dist = c.distance(data);

        if (max_heap.size() < points)
        {
            max_heap.push(std::make_pair(dist, c));
        }
        else
        {
            if (dist < max_heap.top().first)
            {
                max_heap.pop();
                max_heap.push(std::make_pair(dist, c));
            }
        }
    }
    while (!max_heap.empty())
    {
        neighbours.push_back(max_heap.top().second);
        max_heap.pop();
    }*/
    std::reverse(neighbours.begin(), neighbours.end());
    return neighbours;
}
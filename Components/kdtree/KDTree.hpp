#ifndef KDTREE_HPP
#define KDTREE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include "../Vec3D/vec3d.hpp"

struct Neighbor
{
    Vec3D point;
    double distance;
    Neighbor(Vec3D p, double d) : point(p), distance(d) {}
    bool operator<(const Neighbor &other) const
    {
        return distance < other.distance;
    }
};

struct Node
{
    Vec3D data;
    int depth;
    Node *left;
    Node *right;
    Node(Vec3D data, int depth) : data(data), depth(depth), left(NULL), right(NULL) {}
};

class KDTree
{
private:
    Node *root;
    int k;

public:
    KDTree() : root(NULL), k(0) {}
    KDTree(int k) : root(NULL), k(k) {}
    ~KDTree() = default;
    void insert(Vec3D data);
    void print();
    bool search(Vec3D data);
    void clear();
    std::vector<Vec3D> KNN(Vec3D data, int cantPoints);

private:
    void Insert(Node *&root, Vec3D data, int depth);
    void Print(Node *root);
    bool Search(Node *root, Vec3D data, int depth);
    void KNNRecursive(Node *node, Vec3D query, int cantPoints, std::vector<Neighbor> &neighbors);
    double distance(Vec3D a, Vec3D b)
    {
        return std::sqrt(std::pow(a.getX() - b.getX(), 2) + std::pow(a.getY() - b.getY(), 2) + std::pow(a.getZ() - b.getZ(), 2));
    }
};

#endif // KDTREE_HPP
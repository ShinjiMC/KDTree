#ifndef KDTREE_HPP
#define KDTREE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include "../Vec3D/vec3d.hpp"

struct CompareDist
{
    bool operator()(const std::pair<double, Vec3D> &a, const std::pair<double, Vec3D> &b) const
    {
        return a.first < b.first;
    }
};

struct Node
{
    Vec3D data;
    Node *left;
    Node *right;
    Node(Vec3D data) : data(data), left(NULL), right(NULL) {}
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
    void Print(Node *root, int depth);
    bool Search(Node *root, Vec3D data, int depth);
    void KNNRecursive(Node *node, Vec3D query, int cantPoints, std::vector<std::pair<double, Vec3D>> &queue);
    double distance(Vec3D a, Vec3D b)
    {
        return std::sqrt(std::pow(a.getX() - b.getX(), 2) + std::pow(a.getY() - b.getY(), 2) + std::pow(a.getZ() - b.getZ(), 2));
    }
};

#endif // KDTREE_HPP
#ifndef KDTREE_HPP
#define KDTREE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "../Vec3D/vec3d.hpp"

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
    std::vector<Vec3D> KNN(Vec3D data, int points);

private:
    void Insert(Node *&root, Vec3D data, int depth);
    void Print(Node *root, int depth);
    bool Search(Node *root, Vec3D data, int depth);
    void KNN(Node *root, Vec3D data, int depth, int k, std::vector<Vec3D> &neighbours);
};

#endif // KDTREE_HPP
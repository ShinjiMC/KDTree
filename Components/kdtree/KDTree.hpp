#ifndef KDTREE_HPP
#define KDTREE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "../point/Point.hpp"

struct Node
{
    Point data;
    Node *left;
    Node *right;
    Node(Point data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class KDTree
{
private:
    Node *root;
    int k;

public:
    KDTree(int k)
    {
        root = NULL;
        this->k = k;
    }
    void insert(Point data);
    void print();
    bool search(Point data);
    std::vector<Point> KNN(Point data, int k);

private:
    void Insert(Node *&root, Point data, int depth);

    void Print(Node *root, int depth);

    bool Search(Node *root, Point data, int depth);

    void KNN(Node *root, Point data, int depth, int k, std::vector<Point> &neighbours);
};

#endif // KDTREE_HPP
#include "KDTree.hpp"
#include <limits>

void KDTree::insert(Vec3D data)
{
    Insert(root, data, 0);
}

void KDTree::Insert(Node *&root, Vec3D data, int depth)
{
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }
    int cd = depth % k;
    if (cd == 0)
    {
        if (data.getX() < root->data.getX())
            Insert(root->left, data, ++depth);
        else
            Insert(root->right, data, ++depth);
    }
    else if (cd == 1)
    {
        if (data.getY() < root->data.getY())
            Insert(root->left, data, ++depth);
        else
            Insert(root->right, data, ++depth);
    }
    else
    {
        if (data.getZ() < root->data.getZ())
            Insert(root->left, data, ++depth);
        else
            Insert(root->right, data, ++depth);
    }
}

void KDTree::print()
{
    Print(root, 0);
}

void KDTree::Print(Node *root, int depth)
{
    if (root == NULL)
        return;
    Print(root->left, depth++);
    std::cout << "(" << root->data.getX() << ", " << root->data.getY() << ", " << root->data.getZ();
    std::cout << ") Level:" << depth << std::endl;
    Print(root->right, depth++);
}

bool KDTree::search(Vec3D data)
{
    return Search(root, data, 0);
}

bool KDTree::Search(Node *root, Vec3D data, int depth)
{
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    int cd = depth % k;
    if (cd == 0)
    {
        if (data.getX() < root->data.getX())
            return Search(root->left, data, ++depth);
        else
            return Search(root->right, data, ++depth);
    }
    else if (cd == 1)
    {
        if (data.getY() < root->data.getY())
            return Search(root->left, data, ++depth);
        else
            return Search(root->right, data, ++depth);
    }
    else
    {
        if (data.getZ() < root->data.getZ())
            return Search(root->left, data, ++depth);
        else
            return Search(root->right, data, ++depth);
    }
}

void KDTree::clear()
{
    delete root;
    root = NULL;
}

std::vector<Vec3D> KDTree::KNN(Vec3D data, int cantPoints)
{
    std::vector<std::pair<double, Vec3D>> queue;
    queue.reserve(cantPoints);
    KNNRecursive(root, data, cantPoints, queue);
    std::vector<Vec3D> neighbours;
    for (const auto &pair : queue)
        neighbours.push_back(pair.second);
    return neighbours;
}

void KDTree::KNNRecursive(Node *node, Vec3D query, int cantPoints, std::vector<std::pair<double, Vec3D>> &queue)
{
    if (node == nullptr)
        return;

    double dist = distance(node->data, query);
    queue.emplace_back(dist, node->data);

    int axis = 0;
    if (query.getY() < node->data.getY())
        axis = 1;

    Node *firstNode = axis ? node->left : node->right;
    Node *secondNode = axis ? node->right : node->left;

    KNNRecursive(firstNode, query, cantPoints, queue);

    double diff = std::fabs(query.getCord(axis) - node->data.getCord(axis));
    if (queue.size() < cantPoints || diff < queue.back().first)
    {
        KNNRecursive(secondNode, query, cantPoints, queue);
    }

    if (queue.size() > cantPoints * 2)
    {
        // Mantener solo los 'cantPoints' puntos más cercanos
        std::nth_element(queue.begin(), queue.begin() + cantPoints, queue.end(), CompareDist());
        queue.resize(cantPoints);
    }
}
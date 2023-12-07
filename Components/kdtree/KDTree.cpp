#include "KDTree.hpp"

void KDTree::insert(Vec3D data)
{
    Insert(root, data, 0);
}

void KDTree::print()
{
    Print(root, 0);
}

bool KDTree::search(Vec3D data)
{
    return Search(root, data, 0);
}

void KDTree::clear()
{
    delete root;
    root = NULL;
}

std::vector<Vec3D> KDTree::KNN(Vec3D data, int points)
{
    std::vector<Vec3D> neighbours;
    KNN(root, data, 0, points, neighbours);
    return neighbours;
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
            Insert(root->left, data, depth++);
        else
            Insert(root->right, data, depth++);
    }
    else if (cd == 1)
    {
        if (data.getY() < root->data.getY())
            Insert(root->left, data, depth++);
        else
            Insert(root->right, data, depth++);
    }
    else
    {
        if (data.getZ() < root->data.getZ())
            Insert(root->left, data, depth++);
        else
            Insert(root->right, data, depth++);
    }
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
            return Search(root->left, data, depth++);
        else
            return Search(root->right, data, depth++);
    }
    else if (cd == 1)
    {
        if (data.getY() < root->data.getY())
            return Search(root->left, data, depth++);
        else
            return Search(root->right, data, depth++);
    }
    else
    {
        if (data.getZ() < root->data.getZ())
            return Search(root->left, data, depth++);
        else
            return Search(root->right, data, depth++);
    }
}

void KDTree::KNN(Node *root, Vec3D data, int depth, int points, std::vector<Vec3D> &neighbours)
{
    if (root == NULL)
        return;
    if (neighbours.size() == points)
    {
        if (data.distance(neighbours[0]) > data.distance(root->data))
        {
            neighbours.erase(neighbours.begin());
            neighbours.push_back(root->data);
        }
    }
    else
        neighbours.push_back(root->data);
    int cd = depth % k;
    if (cd == 0)
    {
        if (data.getX() < root->data.getX())
            KNN(root->left, data, depth++, points, neighbours);
        else
            KNN(root->right, data, depth++, points, neighbours);
    }
    else if (cd == 1)
    {
        if (data.getY() < root->data.getY())
            KNN(root->left, data, depth++, points, neighbours);
        else
            KNN(root->right, data, depth++, points, neighbours);
    }
    else
    {
        if (data.getZ() < root->data.getZ())
            KNN(root->left, data, depth++, points, neighbours);
        else
            KNN(root->right, data, depth++, points, neighbours);
    }
}
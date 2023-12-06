#include "KDTree.hpp"

void KDTree::insert(Point data)
{
    Insert(root, data, 0);
}

void KDTree::print()
{
    Print(root, 0);
}

bool KDTree::search(Point data)
{
    return Search(root, data, 0);
}

std::vector<Point> KDTree::KNN(Point data, int k)
{
    std::vector<Point> neighbours;
    KNN(root, data, 0, k, neighbours);
    return neighbours;
}

void KDTree::Insert(Node *&root, Point data, int depth)
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
    else
    {
        if (data.getY() < root->data.getY())
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
    root->data.print();
    std::cout << " " << depth << std::endl;
    Print(root->right, depth++);
}

bool KDTree::Search(Node *root, Point data, int depth)
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
    else
    {
        if (data.getY() < root->data.getY())
            return Search(root->left, data, depth++);
        else
            return Search(root->right, data, depth++);
    }
}

void KDTree::KNN(Node *root, Point data, int depth, int k, std::vector<Point> &neighbours)
{
    if (root == NULL)
        return;
    if (neighbours.size() == k)
    {
        if (root->data < neighbours[neighbours.size() - 1])
        {
            neighbours.pop_back();
            neighbours.push_back(root->data);
        }
    }
    else
        neighbours.push_back(root->data);
    std::sort(neighbours.begin(), neighbours.end());
    int cd = depth % k;
    if (cd == 0)
    {
        if (data.getX() < root->data.getX())
            KNN(root->left, data, depth++, k, neighbours);
        else
            KNN(root->right, data, depth++, k, neighbours);
    }
    else
    {
        if (data.getY() < root->data.getY())
            KNN(root->left, data, depth++, k, neighbours);
        else
            KNN(root->right, data, depth++, k, neighbours);
    }
}
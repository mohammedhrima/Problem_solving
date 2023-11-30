
#include <iostream>
#include <vector>

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

std::vector<int> inorderTraversal(Node *root)
{
    std::vector<int> res;
    if (root)
    {
        // left
        std::vector<int> left = inorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());
        // curr
        res.push_back(root->val);
        // right
        std::vector<int> right = inorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());
    }
    return res;
}

void delete_tree(Node *node)
{
    if (node)
    {
        delete_tree(node->left);
        std::cout << node->val << " ";
        delete_tree(node->right);
        delete node;
    }
}

int main()
{
    Node *node = new Node(1);
    node->right = new Node(2);
    node->right->left = new Node(3);
    delete_tree(node);
    std::cout << std::endl;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int value;
} Node;

int *generate_random_numbers(int ranlen)
{
    int len = ranlen + 1;
    int *rans = new int[ranlen];
    int *nums = new int[len];
    for (int i = 0; i < len; i++)
        nums[i] = i + 1;

    srand(time(NULL));
    int randIndex = 0;
    for (int i = 0; i < ranlen; i++)
    {
        while (randIndex == 0 || nums[randIndex] == 0)
            randIndex = rand() % len;
        rans[i] = nums[randIndex];
        nums[randIndex] = 0;
    }
    for (int i = 0; i < ranlen; i++)
        std::cout << rans[i] << " ";
    std::cout << std::endl;
    delete[] nums;
    return rans;
}

Node *new_node(int value)
{
    Node *ptr = new Node;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->value = value;
    return ptr;
}

Node *recursive_insertion(Node *node, int value)
{
    if (node == NULL)
        return new_node(value);
    else if (value < node->value)
        node->left = recursive_insertion(node->left, value);
    else if (value > node->value)
        node->right = recursive_insertion(node->right, value);
    return node;
}

void inorder(Node *node)
{
    if (node)
    {
        inorder(node->left);
        std::cout << (void *)node << " : " << node->value << std::endl;
        inorder(node->right);
    }
}

void free_node(Node *node)
{
    if (node == NULL)
        return;
    if (node->left)
        free_node(node->left);
    if (node->right)
        free_node(node->right);
    delete node;
}

Node *delete_node(Node *root, int value)
{
    if (root == NULL)
        return root;
    if (root->value == value)
    {
        if (root->left == NULL)
        {
            Node *right = root->right;
            delete root;
            return right;
        }
        else if (root->right == NULL)
        {
            Node *left = root->left;
            delete root;
            return left;
        }
        
        Node *Parent = root;
        Node *curr = root->right;

        while (curr->left)
        {
            Parent = curr;
            curr = curr->left;
        }

        if (Parent != root)
            Parent->left = curr->right;
        else
            Parent->right = curr->right;

        root->value = curr->value;
        delete curr;
    }
    if (root->value > value)
        root->left = delete_node(root->left, value);
    if (root->value < value)
        root->right = delete_node(root->right, value);
    return root;
}

int main(void)
{
    int len = 10;
    std::cout << "       ";
    int *nums = generate_random_numbers(len);

    Node *node = NULL;
    for (int i = 0; i < len; i++)
        node = recursive_insertion(node, nums[i]);

    std::cout << "Before deletion : " << std::endl;
    inorder(node);
    std::cout << std::endl;

    node = delete_node(node, nums[1]);
    std::cout << "Delete " << nums[1] << std::endl;
    std::cout << std::endl;

    std::cout << "After deletion : " << std::endl;
    inorder(node);
    std::cout << std::endl;

    free_node(node);
    delete[] nums;
}
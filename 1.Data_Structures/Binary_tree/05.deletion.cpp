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

void print_in_order(Node *node)
{
    if (node)
    {
        print_in_order(node->left);
        std::cout << node->value << " ";
        print_in_order(node->right);
    }
}

void delete_tree(Node *node)
{
    if (node == NULL)
        return;
    if (node->left)
        delete_tree(node->left);
    if (node->right)
        delete_tree(node->right);
    delete node;
}

Node *delete_node(Node *root, int value)
{
    Node *ret;
    if (!root)
        return root;
    if (root->value == value)
    {
        if (root->left == NULL)
        {
            ret = root->right;
            delete root;
            return ret;
        }
        else if (root->right == NULL)
        {
            ret = root->left;
            delete root;
            return ret;
        }
        Node *prev = root;
        Node *curr = root->right;
        while (curr->left != NULL)
        {
            prev = curr;
            curr = curr->left;
        }
        if (prev == root)
            prev->right = curr->right;
        else
            prev->left = curr->right;
        root->value = curr->value;
        delete curr;
    }
    else if (root->value > value)
        root->left = delete_node(root->left, value);
    else if (root->value < value)
        root->right = delete_node(root->right, value);
    return root;
}

int main(void)
{
    int len = 10;
    int *nums = generate_random_numbers(len);
    Node *node = NULL;
    for (int i = 0; i < len; i++)
        node = recursive_insertion(node, nums[i]);

    // print in order
    print_in_order(node);
    std::cout << std::endl;

    std::cout << "delete: " << nums[0] << std::endl;
    delete_node(node, nums[0]);
    print_in_order(node);
    std::cout << std::endl;
    delete[] nums;
    delete_tree(node);
}
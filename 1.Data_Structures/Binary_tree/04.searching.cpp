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

void print_inorder(Node *node)
{
    if (node)
    {
        print_inorder(node->left);
        std::cout << (void *)node << " : " << node->value << std::endl;
        print_inorder(node->right);
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

void *search(Node *node, int value)
{
    void *res = NULL;
    while (node && node->value != value)
    {
        if (node->value > value)
            node = node->left;
        else if (node->value < value)
            node = node->right;
    }
    return (void *)node;
}

int main(void)
{
    int len = 10;
    std::cout << "       ";
    int *nums = generate_random_numbers(len);

    Node *node = NULL;
    for (int i = 0; i < len; i++)
        node = recursive_insertion(node, nums[i]);

    std::cout << "node : " << std::endl;
    print_inorder(node);
    std::cout << std::endl;

    int value = nums[len / 2];
    std::cout << "nums[" << len / 2 << "] = " << nums[len / 2] << " address in nodes: " << search(node, value) << std::endl;

    free_node(node);
    delete[] nums;
}
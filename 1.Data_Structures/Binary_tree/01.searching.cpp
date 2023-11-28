#include <iostream>
#include <cstdlib>
#include <ctime>

int *generate_random_numbers(int ranlen)
{
    int len = ranlen * 10;
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

typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int value;
} Node;

Node *new_node(int value)
{
    Node *ptr = new Node;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->value = value;
    return ptr;
}

Node *insert(Node *node, int value)
{
    if (node == NULL)
        return new_node(value);
    else if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    return node;
}

Node *min_node(Node *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

size_t node_count(Node *node)
{
    if (node == NULL)
        return 0;
    return node_count(node->left) + node_count(node->right) + 1;
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

int main(void)
{
    int len = 10;
    int *nums = generate_random_numbers(len);
    Node *node = NULL;
    for (int i = 0; i < len; i++)
        node = insert(node, nums[i]);
    std::cout << "Min value : " << min_node(node)->value << std::endl;
    std::cout << "Node count: " << node_count(node) << std::endl;
    free_node(node);
    delete[] nums;
}
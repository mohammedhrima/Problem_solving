#include <iostream>
#include <cstdlib>
#include <ctime>
/*
left  key lesser  than curr key
right key greater than curr key
*/

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

Node *iterative_insertion(Node *node, int value)
{
    if (node == NULL)
        return new_node(value);

    Node *curr;
    Node *tmp = node;
    while (tmp)
    {
        curr = tmp;
        if (tmp->value > value)
            tmp = tmp->left;
        else if (tmp->value < value)
            tmp = tmp->right;
    }
    if (curr->value > value)
        curr->left = new_node(value);
    else if (curr->value < value)
        curr->right = new_node(value);
    return node;
}

void inorder(Node *node)
{
    if (node)
    {
        inorder(node->left);
        std::cout << node->value << " ";
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

int main(void)
{
    int len = 10;
    std::cout << "        ";
    int *nums = generate_random_numbers(len);

    Node *node0 = NULL;
    Node *node1 = NULL;
    for (int i = 0; i < len; i++)
    {
        node0 = recursive_insertion(node0, nums[i]);
        node1 = iterative_insertion(node1, nums[i]);
    }

    std::cout << "node0 : ";
    inorder(node0);
    std::cout << std::endl;
    std::cout << "node1 : ";
    inorder(node1);
    std::cout << std::endl;

    free_node(node0);
    free_node(node1);
    delete[] nums;
}
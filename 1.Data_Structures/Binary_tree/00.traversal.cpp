#include <iostream>
#include <cstdlib>
#include <ctime>
/*
left  key lesser  than curr key
right key greater than curr key
*/

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

void inorder(Node *node)
{
    if (node)
    {
        inorder(node->left);
        std::cout << node->value << " ";
        inorder(node->right);
    }
}

void preorder(Node *node)
{
    if (node)
    {
        std::cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(Node *node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->value << " ";
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
    std::cout << "            ";
    int *nums = generate_random_numbers(len);
    Node *node = NULL;
    for (int i = 0; i < len; i++)
        node = insert(node, nums[i]);

    std::cout << "Head      : ";
    std::cout << node->value << std::endl;

    std::cout << "Inorder   : ";
    inorder(node);
    std::cout << std::endl;

    std::cout << "Preorder  : ";
    preorder(node);
    std::cout << std::endl;

    std::cout << "Postorder : ";
    postorder(node);
    std::cout << std::endl;

    free_node(node);
    delete[] nums;
}
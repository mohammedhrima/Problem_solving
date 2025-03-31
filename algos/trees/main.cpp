#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

vector<int>generate_random_numbers(int ranlen)
{
    srand(time(NULL));
    vector<int> rans(ranlen);
    for (int i = 0; i < ranlen; i++)  rans[i] = rand() % 100; 
    cout << "Generated : ";
    for (auto e : rans) cout << e << " ";
    cout << endl;

    return rans;
}

struct Node
{
    struct Node *left;
    struct Node *right;
    int value;

    Node(int v) : value(v) { left = NULL, right = NULL;};
} ;


Node *insert(Node *node, int value)
{
    if (node == NULL) return new Node(value);
    else if (value < node->value) node->left = insert(node->left, value);
    else if (value > node->value) node->right = insert(node->right, value);
    return node;
}

void print_inorder(Node *node)
{
    if (!node) return;
    print_inorder(node->left);
    cout << node->value << " ";
    print_inorder(node->right);
}

void preorder(Node *node)
{
    if (!node) return;
    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node *node)
{
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}

void free_node(Node *node)
{
    if (node == NULL) return;
    if (node->left) free_node(node->left);
    if (node->right) free_node(node->right);
    delete node;
}

size_t node_size(Node *node)
{
    if (node == NULL) return 0;
    return node_size(node->left) + node_size(node->right) + 1;
}

Node *min_node(Node *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

Node *recursive_insertion(Node *node, int value)
{
    if (node == NULL) return new Node(value);
    else if (value < node->value) node->left = recursive_insertion(node->left, value);
    else if (value > node->value) node->right = recursive_insertion(node->right, value);
    return node;
}

Node* iterative_insertion(Node *node, int value) {
    if (node == NULL) return new Node(value);

    Node *curr = node;
    while (true) {
        if (value < curr->value) 
        {
            if (curr->left == NULL) 
            {
                curr->left = new Node(value);
                break;
            }
            curr = curr->left;
        } 
        else if (value > curr->value) 
        {
            if (curr->right == NULL) 
            {
                curr->right = new Node(value);
                break;
            }
            curr = curr->right;
        } 
        else break; // value already exists
    }
    return node;
}


Node *iterative_search(Node *node, int value)
{
    while (node && node->value != value)
    {
        if (node->value > value) node = node->left;
        else if (node->value < value) node = node->right;
    }
    return node;
}

Node *recursive_search(Node *node, int value)
{
    if (node->value > value) return recursive_search(node->left, value);
    else if (node->value < value) return recursive_search(node->right, value);
    return node;
}

Node *delete_node(Node *root, int value)
{
    Node *ret;
    if (!root) return root;
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
        if (prev == root) prev->right = curr->right;
        else prev->left = curr->right;
        root->value = curr->value;
        delete curr;
    }
    else if (root->value > value) root->left = delete_node(root->left, value);
    else if (root->value < value) root->right = delete_node(root->right, value);
    return root;
}

int main(void)
{
    cout << "==========================" << endl;
    vector<int> nums = generate_random_numbers(10);
    Node *node = NULL;
    for (int i = 0; i < nums.size(); i++) node = insert(node, nums[i]);

    cout << "Head      : " << node->value << endl;
    cout << "Min node  : " << min_node(node)->value << endl;
    cout << "Size      : " << node_size(node) << endl;

    cout << "Inorder   : ";
    print_inorder(node);
    cout << endl;

    cout << "Preorder  : ";
    preorder(node);
    cout << endl;

    cout << "Postorder : ";
    postorder(node);
    cout << endl;

    free_node(node);
}
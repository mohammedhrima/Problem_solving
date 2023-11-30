#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode Node;
void delete_tree(Node *root)
{
    if (root)
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

Node *recursive_insertion(Node *arr[], int i, size_t len)
{
    if (i >= len || arr[i] == NULL)
        return NULL;
    Node *node = arr[i];
    node->left = recursive_insertion(arr, i * 2 + 1, len);
    node->right = recursive_insertion(arr, i * 2 + 2, len);
    return node;
}

Node *iterative_insertion(Node *arr[], size_t len)
{
    size_t i = 0;
    while (i < len)
    {
        Node *node = arr[i];
        int l = i * 2 + 1;
        if (l < len)
            node->left = arr[l];
        int r = i * 2 + 2;
        if (r < len)
            node->right = arr[r];
        i++;
    }
    return arr[0];
}

void print_tree(Node *root)
{
    if (root)
    {
        std::cout << root->val << " ";
        print_tree(root->left);
        print_tree(root->right);
    }
}

void append(Node *node, std::vector<int> &v)
{
    if (node)
    {
        append(node->left, v);
        v.push_back(node->val);
        append(node->right, v);
    }
}

bool isValidBST(Node *root)
{
    std::vector<int> v;
    append(root, v);
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] >= v[i + 1])
            return false;
    }
    return true;
}

int main(void)
{
    Node *arr[] = {new Node(5), new Node(1), new Node(6), NULL, NULL, new Node(5), new Node(7)};
    size_t len = sizeof(arr) / sizeof(*arr);
    Node *root;
#if 0
    root = recursive_insertion(arr, 0, len);
#else
    root = iterative_insertion(arr, len);
#endif
    print_tree(root);
    std::cout << std::endl;
    std::cout << "isValid: " << (isValidBST(root) ? "true" : "false") << std::endl;
    delete_tree(root);
}
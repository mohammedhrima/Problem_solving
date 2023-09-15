#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode Node;
int maxDepth(struct TreeNode *root)
{
    if (!root)
        return 0;
    int left = 1;
    int right = 1;
    if (root->left)
        left += maxDepth(root->left);
    if (root->right)
        right += maxDepth(root->right);
    return left > right ? left : right;
}

int main(void)
{
}
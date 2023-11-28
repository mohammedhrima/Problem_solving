#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if ((!p && q) || (p && !q))
        return false;
    if (!p && !q)
        return true;
    if (p->val != q->val)
        return false;
    if (!isSameTree(p->right, q->right))
        return false;
    if (!isSameTree(p->left, q->left))
        return false;
    return true;
}
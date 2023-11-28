#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool check(struct TreeNode *left, struct TreeNode *right)
{
    if(!left && !right) return true;
    if((left && !right) || (!left && right)) return false;
    if(left->val != right->val) return false;
    if(!check(left->left, right->right) || !check(left->right, right->left))
        return false;
    return true;
}

bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL) return true;
    return check(root->left, root->right);
}

int main(void)
{

}
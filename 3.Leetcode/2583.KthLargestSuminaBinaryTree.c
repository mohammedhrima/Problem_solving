#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *new_node(int val)
{
    Node *new = calloc(1, sizeof(Node));
    new->val = val;
    return new;
}

Node *insert(int arr[], int len)
{
    if (len == 0)
        return NULL;

    int l = 0;
    int r = 0;
    Node **queue = calloc(len + 1, sizeof(Node *));
    Node *root = new_node(arr[0]);
    queue[r++] = root;

    while (l < r)
    {
        Node *node = queue[l];
        if (l * 2 + 1 < len)
            queue[r++] = (node->left = new_node(arr[l * 2 + 1]));
        if (l * 2 + 2 < len)
            queue[r++] = (node->right = new_node(arr[l * 2 + 2]));
        l++;
    }
    free(queue);
    return root;
}

void print_tree(Node *node)
{
    if (node)
    {
        print_tree(node->left);
        print_tree(node->right);
        printf("%d ", node->val);
    }
}

void clear_tree(Node *node)
{
    if (node)
    {
        clear_tree(node->left);
        clear_tree(node->right);
        free(node);
    }
}

void depth_search(Node *node, int *sums, int k)
{
    if (node && k > 0)
    {
        sums[k - 1] += node->val;
        depth_search(node->left, sums, k - 1);
        depth_search(node->right, sums, k - 1);
    }
}

size_t tree_depth(Node *node, long long *nums, int d)
{
    if (node)
    {
        size_t res = 1;
        int l = tree_depth(node->left, nums, d + 1);
        int r = tree_depth(node->right, nums, d + 1);
        if (l > r)
            res += l;
        else
            res += r;
        nums[d] += node->val;
        return res;
    }
    return 0;
}

void mergeSort(long long *array, size_t len)
{
    if (len >= 2)
    {
        long long *left = calloc(len / 2 + 1, sizeof(long long));
        long long *right = calloc(len / 2 + len % 2 + 1, sizeof(long long));
        memcpy(left, array, (len / 2) * sizeof(long long));
        memcpy(right, array + len / 2, (len / 2 + len % 2) * sizeof(long long));
        // recursion
        mergeSort(left, len / 2);
        mergeSort(right, len / 2 + len % 2);
        // merge
        size_t i = 0;
        size_t j = 0;
        size_t k = 0;
        while (i < len / 2 && j < len / 2 + len % 2)
            array[k++] = left[i] < right[j] ? left[i++] : right[j++];
        while (i < len / 2)
            array[k++] = left[i++];
        while (j < len / 2 + len % 2)
            array[k++] = right[j++];
        free(left);
        free(right);
    }
}

long long kthLargestLevelSum(Node *root, int k)
{
    long long *sums = calloc(150000, sizeof(long long));
    size_t depth = tree_depth(root, sums, 0);
    long long res;
    if (depth < k)
        res = -1;
    else
    {
        mergeSort(sums, depth);
        res = sums[depth - k];
    }
    free(sums);
    return res;
}

int main(void)
{
    int arr[] = {5, 8, 9, 2, 1, 3, 7, 4, 6};
    int *sums = calloc(100, sizeof(int));
    int len;
    Node *node = NULL;
#if 0
    len = sizeof(arr) / sizeof(int);
    node = insert(arr, len);
    print_tree(node);
    printf("\n-> %lld\n", kthLargestLevelSum(node, 2));
#elif 0
    node = new_node(1);
    node->left = new_node(2);
    node->left->left = new_node(3);
    printf("\n-> %lld\n", kthLargestLevelSum(node, 1));
#elif 1
    node = new_node(605481);
    node->right = new_node(87336);
    node->right->right = new_node(226750);
    printf("\n-> %lld\n", kthLargestLevelSum(node, 1));
#endif
    // printf("-> %d\n", kthLargestLevelSum(node, 1));
    clear_tree(node);
    free(sums);
}

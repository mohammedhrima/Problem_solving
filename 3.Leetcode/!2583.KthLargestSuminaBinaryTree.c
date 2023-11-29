
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
    int l = 0;
    int r = 0;
    Node **queue = calloc(len + 1, sizeof(Node *));
    Node *root = new_node(arr[0]);
    queue[r++] = root;

    while (r - l > 0)
    {
        Node *node = queue[l];
        if (l * 2 + 1 < len)
        {
            node->left = new_node(arr[l * 2 + 1]);
            queue[r++] = node->left;
        }
        if (l * 2 + 2 < len)
        {
            node->right = new_node(arr[2 * l + 2]);
            queue[r++] = node->right;
        }
        l++;
    }
    free(queue);
    return root;
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

void print_tree(Node *node, int len)
{
    int l = 0;
    int r = 0;
    Node **queue = calloc(len + 1, sizeof(Node *));

    queue[r++] = node;

    while (l < r)
    {
        Node *node = queue[l];

        printf("%d ", node->val);
        if (node->left)
            queue[r++] = node->left;
        if (node->right)
            queue[r++] = node->right;
        l++;
    }
    free(queue);
    printf("\n");
}

void mergeSort(int *array, int len)
{
    if (len >= 2)
    {
        int *left = calloc(len / 2 + 1, sizeof(int));
        int *right = calloc(len / 2 + len % 2 + 1, sizeof(int));
        memcpy(left, array, (len / 2) * sizeof(int));
        memcpy(right, array + len / 2, (len / 2 + len % 2) * sizeof(int));
        // recursion
        mergeSort(left, len / 2);
        mergeSort(right, len / 2 + len % 2);
        // merge
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < len / 2 && j < len / 2 + len % 2)
            array[k++] = left[i] > right[j] ? left[i++] : right[j++];
        while (i < len / 2)
            array[k++] = left[i++];
        while (j < len / 2 + len % 2)
            array[k++] = right[j++];
        free(left);
        free(right);
    }
}

int kthLargestLevelSum(Node *root, int k)
{
    int l = 0;
    int r = 0;
    int i = 0;
    int res = 0;

    Node **queue = calloc(150000, sizeof(Node *));
    int *sums = calloc(150000, sizeof(int));
    queue[r] = root;
    r++;
    while (l < r)
    {
        Node *node = queue[l];
        if (node->left)
            queue[r++] = node->left;
        if (node->right)
            queue[r++] = node->right;
        l++;
    }
    l = 0;
    while (l < r)
    {
        int tmp = (l * 2) + 1;
        if (tmp > r)
            tmp = r;
        while (l < tmp && queue[l])
        {
            sums[i] += queue[l]->val;
            l++;
        }
        printf("sums[%d]=%d\n", i, sums[i]);
        i++;
    }

    mergeSort(sums, i);
    printf("after sorting\n");
    for (int j = 0; j < i; j++)
        printf("%d, ", sums[j]);
    printf("\n");

    if (k - 1 < i)
        res = sums[k - 1];
    else
        res = -1;
    free(queue);
    free(sums);
    return res;
}

int main(void)
{
    int arr[] = {5, 8, 9, 2, 1, 3, 7, 4, 6};
    int len;
    Node *node = NULL;
#if 0
    len =  sizeof(arr) / sizeof(int);
    node = insert(arr, len);
#else
    node = new_node(1);
    node->left = new_node(2);
    node->left->left = new_node(3);
    len = 3;
#endif
    print_tree(node, len);
    printf("-> %d\n", kthLargestLevelSum(node, 2));
    clear_tree(node);
}
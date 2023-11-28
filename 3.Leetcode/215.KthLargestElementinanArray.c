#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeReverseSort(int *array, int len)
{
    if (len >= 2)
    {
        int *left = calloc(len / 2 + 1, sizeof(int));
        int *right = calloc(len / 2 + len % 2 + 1, sizeof(int));
        memcpy(left, array, (len / 2) * sizeof(int));
        memcpy(right, array + len / 2, (len / 2 + len % 2) * sizeof(int));
        // recursion
        mergeReverseSort(left, len / 2);
        mergeReverseSort(right, len / 2 + len % 2);
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

int findKthLargest(int *nums, int numsSize, int k)
{
    mergeReverseSort(nums, numsSize);
    return nums[k - 1];
}

int main(void)
{
    int array[] = {3,2,3,1,2,4,5,5,6};
    int len = sizeof(array) / sizeof(int);
    printf("%d\n", findKthLargest(array, len, 4));
}
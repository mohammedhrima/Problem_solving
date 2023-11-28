#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
            array[k++] = left[i] < right[j] ? left[i++] : right[j++];
        while (i < len / 2)
            array[k++] = left[i++];
        while (j < len / 2 + len % 2)
            array[k++] = right[j++];
        free(left);
        free(right);
    }
}

bool containsDuplicate(int *nums, int numsSize)
{
    mergeSort(nums, numsSize);
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            return true;
    }
    return false;
}
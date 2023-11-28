#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort(int *arr, int len)
{
    if (len > 1)
    {
        int *left = calloc(len / 2, sizeof(int));
        int *right = calloc(len / 2 + len % 2, sizeof(int));
        memcpy(left, arr, len / 2 * sizeof(int));
        memcpy(right, arr + len / 2, (len / 2 + len % 2) * sizeof(int));
        mergeSort(left, len / 2);
        mergeSort(right, len / 2 + len % 2);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < len / 2 && j < len / 2 + len % 2)
            arr[k++] = left[i] < right[j] ? left[i++] : right[j++];
        while (i < len / 2)
            arr[k++] = left[i++];
        while (j < len / 2 + len % 2)
            arr[k++] = right[j++];
        free(left);
        free(right);
    }
}

int majorityElement(int *nums, int numsSize)
{
    mergeSort(nums, numsSize);
    int repeated = nums[0];
    int maxrep = 0;
    int i = 0;
    while (i < numsSize)
    {
        int j = i;
        while (j < numsSize && nums[i] == nums[j])
            j++;
        if(j - i > maxrep)
        {
            repeated = nums[i];
            maxrep = j - i;
        }
        i = j;
    }
    return repeated;
}

int main(void)
{
    int nums[] = {2,2,1,1,1,2,2};
    int len = sizeof(nums) / sizeof(int);
    printf("%d\n", majorityElement(nums, len));
}
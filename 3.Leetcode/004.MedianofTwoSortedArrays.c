
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mergeSort2(int *array, int len)
{
    if (len > 1)
    {
        int *left = malloc(sizeof(int) * (len / 2));
        int *right = malloc(sizeof(int) * (len / 2 + len % 2));
        memcpy(left, array, sizeof(int) * (len / 2));
        memcpy(right, array + len / 2, sizeof(int) * (len / 2 + len % 2));

        // recursion
        mergeSort2(left, len / 2);
        mergeSort2(right, len / 2 + len % 2);

        // merge
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < len / 2 && j < len / 2 + len % 2)
        {
            if (left[i] < right[j])
            {
                array[k] = left[i];
                i++;
            }
            else
            {
                array[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < len / 2)
        {
            array[k] = left[i];
            i++;
            k++;
        }
        while (j < len / 2 + len % 2)
        {
            array[k] = right[j];
            j++;
            k++;
        }
        free(left);
        free(right);
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int *array = calloc(nums1Size + nums2Size + 1, sizeof(int));
    memcpy(array, nums1, nums1Size * sizeof(int));
    memcpy(array + nums1Size, nums2, nums2Size * sizeof(int));
    int len = nums1Size + nums2Size;
    mergeSort2(array, len);
    double ret;
    if (len % 2)
        ret = (double)(array[len / 2]);
    else
        ret = (double)(array[len / 2] + array[len / 2 - 1]) / 2;
    free(array);
    return ret;
}

int main(void)
{
    int arr1[] = {1, 3};
    int arr2[] = {2};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    printf("%f\n", findMedianSortedArrays(arr1, len1, arr2, len2));
}
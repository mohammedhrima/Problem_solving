#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeInsertion(int *arr, int len)
{
    if (len >= 8)
    {
        int *left = calloc(len / 2 + 1, sizeof(int));
        int *right = calloc(len / 2 + len % 2 + 1, sizeof(int));
        memcpy(left, arr, (len / 2) * sizeof(int));
        memcpy(right, arr + len / 2, (len / 2 + len % 2) * sizeof(int));
        // recursion
        mergeInsertion(left, len / 2);
        mergeInsertion(right, len / 2 + len % 2);
        // merge
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
    else if (len >= 2)
    {
        // insertion
        for (int i = 1; i < len; i++)
        {
            int curr = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > curr)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = curr;
        }
    }
}

int main(void)
{
    int array[] = {1, 3, 5, 1, 7, 4, 4, 4, 0, 2, 6, 0};
    int len = sizeof(array) / sizeof(int);
    printf("\n");
    mergeInsertion(array, len);
    int i = 0;
    while (i < len)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
}
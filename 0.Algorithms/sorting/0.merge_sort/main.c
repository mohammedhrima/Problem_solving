#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort1(int *array, int len)
{
    if (len >= 2)
    {
        int *left = calloc(len / 2 + 1, sizeof(int));
        int *right = calloc(len / 2 + len % 2 + 1, sizeof(int));
        memcpy(left, array, (len / 2) * sizeof(int));
        memcpy(right, array + len / 2, (len / 2 + len % 2) * sizeof(int));
        // recursion
        mergeSort1(left, len / 2);
        mergeSort1(right, len / 2 + len % 2);
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


int main(void)
{
    int array[] = {1, 3, 5, 1, 7, 4, 4, 4, 0, 2, 6, 0};
    int len = sizeof(array) / sizeof(int);
    int i = 0;
    while (i < len)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
    mergeSort2(array, len);
    i = 0;
    while (i < len)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
}
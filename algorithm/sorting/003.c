#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int *array, int len)
{
    if (len > 1)
    {
        int *left_array = malloc((len / 2) * sizeof(int));
        int *right_array = malloc((len / 2 + len % 2) * sizeof(int));
        memcpy(left_array, array, sizeof(int) * (len / 2));
        memcpy(right_array, array + len / 2, sizeof(int) * (len / 2 + len % 2));
        // recursion
        merge_sort(left_array, len / 2);
        merge_sort(right_array, len / 2 + len % 2);

        // merge
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < len / 2 && j < len / 2 + len % 2)
        {
            if (left_array[i] < right_array[j])
            {
                array[k] = left_array[i];
                i++;
            }
            else
            {
                array[k] = right_array[j];
                j++;
            }
            k++;
        }
        while (i < len / 2)
        {
            array[k] = left_array[i];
            i++;
            k++;
        }
        while (j < len / 2 + len % 2)
        {
            array[k] = right_array[j];
            j++;
            k++;
        }
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
    merge_sort(array, len);
    i = 0;
    while (i < len)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
}
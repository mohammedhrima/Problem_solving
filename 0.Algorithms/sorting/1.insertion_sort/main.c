#include <stdio.h>

void insertionSort(int *arr, int len)
{
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

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int len = sizeof(arr) / sizeof(int);
    insertionSort(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
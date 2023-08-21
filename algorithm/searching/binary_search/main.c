#include <stdio.h>

// used for a sorted list
int binarySearch(int arr[], int left, int right, int to_find)
{
    while (left <= right)
    {
        int i = left + (right - left) / 2;

        if (arr[i] == to_find) // found in index i
            return i;
        if (arr[i] > i) 
            left = i + 1;
        if(arr[i] < i)
            right = i - 1;
    }
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int to_find = 10;
    int len = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, len - 1, to_find);

    printf("result: %d\n", result);
}
#include <stdio.h>
#include <stdbool.h>

// front and back algorithm used for any type of list (sorted or unsorted)
bool fab_search1(int array[], int len, int to_find)
{
    int front = 0;
    int back = len - 1;

    while (front <= back)
    {
        if (array[front] == to_find || array[back] == to_find)
            return true;
        front++;
        back--;
    }
    return false;
}

bool fab_search2(int array[], int len, int to_find)
{
    int i = 0;

    while (i <= len - i - 1)
    {
        if (array[i] == to_find || array[len - i - 1] == to_find)
            return true;
        i++;
    }
    return false;
}

int main(void)
{
    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int x = 1300;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (fab_search2(arr, n, x))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
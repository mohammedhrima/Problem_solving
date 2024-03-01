#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i; j < numsSize; j++)
        {
            if (nums[i] == nums[j] && abs(i - j) < k)
                return true;
        }
    }
    return false;
}

int main()
{
    struct
    {
        int *nums;
        int numsSize;
        int k;
        bool res;
    } v[] = {
        {(int[]){1, 2, 3, 1},
         4,
         3,
         true},
        {(int[]){1, 0, 1, 1},
         4,
         1,
         true},
        {(int[]){1, 2, 3, 1, 2, 3},
         6,
         2,
         false},
        {0, 0, 0, 0}};
    // for (int i = 0; v[i].nums; i++)
    //     printf("%d\n", containsNearbyDuplicate(v[i].nums, v[i].numsSize, v[i].k) == v[i].res);
    int i = 2;
    printf("%d\n", containsNearbyDuplicate(v[i].nums, v[i].numsSize, v[i].k) == v[i].res);
}
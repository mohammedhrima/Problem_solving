#include <stdio.h>

void rotate(int *nums, int numsSize, int k)
{
    k = k % numsSize;
    int temp[numsSize];
    for (int i = 0; i < numsSize; i++)
        temp[i] = nums[(i + numsSize - k) % numsSize];
    for (int i = 0; i < numsSize; i++)
        nums[i] = temp[i];
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    int numsSize = sizeof(nums) / sizeof(int);
    int k = 3; // Number of rotations

    rotateArray(nums, numsSize, k);
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
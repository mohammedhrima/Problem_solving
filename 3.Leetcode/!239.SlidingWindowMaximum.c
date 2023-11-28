#include <stdio.h>
#include <stdlib.h>

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
    *returnSize = numsSize - k + 1;
    
    int *res = calloc(*returnSize + 1, sizeof(int));
    int j = 0;

    int firstmax = nums[numsSize - 1];
    int secondmax = firstmax;
    
    int leftend = numsSize - k - 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        if(i == leftend)
        {
            leftend -= k;
        }
    }
    return res;
}

int get_max(int l, int r)
{
    
}

int main(void)
{
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int len = sizeof(nums) / sizeof(int);
    int n = 0;
    maxSlidingWindow(&nums[0], len, k, &n);


    // m[i][p] = max(arr[i .. i + 2^p - 1])

    // 1,3,-1,-3 ,5,3,6,7

    // m[0][3] = max(m[0][2], m[4][2])

    // for (int i = 0; i < n; i++)
    //     m[i][0] = a[i];

    // for (int p = 1; p < 32; p++)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         m[i][p] = max(m[i][p - 1], m[i + 2^(p - 1)]);
    //     }
    // }


}
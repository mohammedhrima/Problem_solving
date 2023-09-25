void moveZeroes(int *nums, int numsSize)
{
    int i = 0;
    int j = 0;
    while (i < numsSize)
    {
        if (nums[i] != 0)
            nums[j++] = nums[i];
        i++;
    }
    while (j < numsSize)
        nums[j++] = 0;
}
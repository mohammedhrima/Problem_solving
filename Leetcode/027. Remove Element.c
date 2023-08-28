#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int i = 0;
    int j = 0;
    while(i < numsSize)
    {
        while(nums[i] == val)
            i++;
        if(i == numsSize)
            break;
        nums[j] = nums[i];
        j++;
    }
    return j;
}

int main(void)
{

}
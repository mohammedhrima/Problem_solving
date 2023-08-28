#include <stdio.h>
#include <stdlib.h>

// check NULL !!
int removeDuplicates(int* nums, int numsSize){
    if(nums == NULL) return 0;

    int i = 0;
    int j = 0;
    while(i < numsSize)
    {
        if(nums[i] != nums[j])
        {
            j++;
            nums[j] = nums[i];
        }
        i++;
    }
    j++;
    // i = 0;
    // while(i < j)
    // {
    //     printf("%d ", nums[i]);
    //     i++;
    // }
    return j;
}

int main(void)
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(nums, sizeof(nums)/sizeof(int));
}
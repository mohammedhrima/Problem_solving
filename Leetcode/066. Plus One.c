#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int if_allNine(int *list, int len)
{
    int i = 0;
    while(i < len)
    {
        if(list[i] != 9)
            return len;
        i++;
    }
    return len + 1;
}

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    *returnSize = if_allNine(digits, digitsSize);
    int *res = calloc(*returnSize + 1, sizeof(int));

    int i = digitsSize - 1;
    int j = *returnSize - 1;
    digits[i]++;
    while(i > -1)
    {
        res[j] += digits[i];
        if(res[j] >= 10)
        {
            res[j - 1] += res[j] / 10;
            res[j] = res[j] % 10;
        }
        j--;
        i--;
    }

    return res;
}

int main(void)
{
    int nums[] = {1, 9, 9, 9};
    int len = 0;
    int *list = plusOne(nums, sizeof(nums) / sizeof(int), &len);
    int i = 0;
    while(i < len)
    {
        printf("%d ", list[i]);
        i++;
    }
    printf("\n");
}
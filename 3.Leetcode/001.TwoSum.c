#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* size){
    int *res = malloc(sizeof(int) * 2);
    *size = 2;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return res;
}

// int main() {
//     int arr[] = {2, 7, 11, 15};
//     int target = 9;
//     int size = sizeof(arr) / sizeof(arr[0]);

//     twoSum(arr, size, target);

//     return 0;
// }
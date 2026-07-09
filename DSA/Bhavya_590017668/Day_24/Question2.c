#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ans = (int*)malloc(numsSize * sizeof(int));

    int left = 0, right = numsSize - 1;
    int index = numsSize - 1;

    while (left <= right) {
        if (nums[left] * nums[left] > nums[right] * nums[right]) {
            ans[index] = nums[left] * nums[left];
            left++;
        } else {
            ans[index] = nums[right] * nums[right];
            right--;
        }
        index--;
    }

    return ans;
}
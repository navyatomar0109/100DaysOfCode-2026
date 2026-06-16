#include <stdio.h>

int missingNumber(int nums[], int numsSize) {
    int expectedSum = numsSize * (numsSize + 1) / 2;
    int actualSum = 0;

    // Array ke sabhi elements ka sum nikalo
    for (int i = 0; i < numsSize; i++) {
        actualSum += nums[i];
    }

    // Missing number return karo
    return expectedSum - actualSum;
}

int main() {
    int nums[] = {3, 0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = missingNumber(nums, numsSize);

    printf("Missing Number = %d\n", result);

    return 0;
}

#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int expectedSum = numsSize * (numsSize + 1) / 2;
    int actualSum = 0;

    for(int i = 0; i < numsSize; i++) {
        actualSum += nums[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d numbers:\n", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = missingNumber(nums, n);

    printf("Missing Number = %d\n", result);

    return 0;
}
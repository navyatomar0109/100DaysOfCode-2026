#include <stdio.h>

int missingNum(int nums[], int numSize) {
    int expSum = numSize * (numSize + 1) / 2;
    int actualSum = 0;

    for(int i = 0; i < numSize; i++) {
        actualSum += nums[i];
    }

    return expSum - actualSum;
}

int main() {
    int nums[] = {3, 0, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Missing Number: %d\n", missingNumber(nums, size));

    return 0;
}

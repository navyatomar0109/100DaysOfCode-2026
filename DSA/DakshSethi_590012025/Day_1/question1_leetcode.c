int missingNumber(int* nums, int numsSize) {
    int e = numsSize * (numsSize + 1) / 2;
    int a = 0;

    for (int i = 0; i < numsSize; i++) {
        a += nums[i];
    }

    return e-a;
}
int missingNumber(int* nums, int numsSize) {
    int xor = numsSize;

    for (int i = 0; i < numsSize; i++) {
        xor ^= i;
        xor ^= nums[i];
    }

    return xor;
}
int triangleNumber(int* nums, int numsSize) {
    int count = 0;

    // sort array
    for (int i = 0; i < numsSize - 1; i++)
        for (int j = 0; j < numsSize - i - 1; j++)
            if (nums[j] > nums[j + 1]) {
                int t = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = t;
            }

    for (int k = numsSize - 1; k >= 2; k--) {
        int left = 0, right = k - 1;

        while (left < right) {
            if (nums[left] + nums[right] > nums[k]) {
                count += right - left;
                right--;
            } else {
                left++;
            }
        }
    }

    return count;
}

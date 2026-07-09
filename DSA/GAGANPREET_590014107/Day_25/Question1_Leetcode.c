#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int triangleNumber(int* nums, int numsSize) {

    int count = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = numsSize - 1; i >= 2; i--) {

        int left = 0;
        int right = i - 1;

        while(left < right) {

            if(nums[left] + nums[right] > nums[i]) {
                count += right - left;
                right--;
            }
            else {
                left++;
            }
        }
    }

    return count;
}

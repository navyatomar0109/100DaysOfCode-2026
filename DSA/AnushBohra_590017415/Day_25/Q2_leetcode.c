#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int triangleNumber(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    int count = 0;
    
    for (int i = numsSize - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;
        
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                count += (right - left);
                right--;
            } else {
                left++;
            }
        }
    }
    
    return count;
}

int main() {
    int test1[] = {2, 2, 3, 4};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    printf("Test 1 Result: %d\n", triangleNumber(test1, size1));

    int test2[] = {4, 2, 3, 4};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    printf("Test 2 Result: %d\n", triangleNumber(test2, size2));

    return 0;
}
//1.
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int triangleNumber(int nums[], int n) {

    qsort(nums, n, sizeof(int), compare);

    int count = 0;

    for (int k = n - 1; k >= 2; k--) {

        int left = 0;
        int right = k - 1;

        while (left < right) {

            if (nums[left] + nums[right] > nums[k]) {
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

    int nums[] = {2, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Number of Valid Triangles: %d\n", triangleNumber(nums, n));

    return 0;
}
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
                count += right - left;
                right--;
            } else {
                left++;
            }
        }
    }

    return count;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = triangleNumber(nums, n);

    printf("Number of valid triangles = %d\n", result);

    return 0;
}
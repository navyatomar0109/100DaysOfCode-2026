<h2 align="center">Week 4 Day 25 (07/09/2026)</h2>

## 1. Valid Triangle Number (LeetCode #611)

### Solution

```c
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int triangleNumber(int* nums, int numsSize) {
    // A triangle requires at least 3 sides
    if (numsSize < 3)
        return 0;

    // Sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);

    int count = 0;

    // Fix the largest side of the triangle
    for (int k = numsSize - 1; k >= 2; k--) {
        int left = 0;
        int right = k - 1;

        // Use two pointers to find valid pairs
        while (left < right) {
            // If the two smaller sides form a valid triangle
            if (nums[left] + nums[right] > nums[k]) {
                // Every element between left and right
                // will also satisfy the condition
                count += (right - left);
                // Try the next smaller value
                right--;
            }
            else {
                // Increase the smaller side
                left++;
            }
        }
    }

    return count;
}
```

---

## 2. Pair with Target Sum

### Solution

```c
#include <stdio.h>
#include <stdbool.h>

// Function to check if a pair with the target sum exists
bool hasPairWithTarget(int arr[], int size, int target) {
    // Initialize two pointers
    int left = 0;
    int right = size - 1;

    // Continue until the pointers meet
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Pair found
        if (sum == target) {
            return true;
        }
        // If sum is smaller, move the left pointer forward
        if (sum < target) {
            left++;
        }
        // If sum is larger, move the right pointer backward
        else {
            right--;
        }
    }

    // No valid pair found
    return false;
}

int main() {
    int size, target;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input the sorted array elements
    printf("Enter the sorted array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target value
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Check if a valid pair exists
    if (hasPairWithTarget(arr, size, target))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
```

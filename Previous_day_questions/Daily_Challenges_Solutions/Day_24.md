<h2 align="center">Week 4 Day 24 (07/08/2026)</h2>

## 1. Happy Number (LeetCode #202)

### Solution

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to calculate the sum of the squares of digits
int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;          // Extract the last digit
        sum += digit * digit;        // Add its square
        n /= 10;                     // Remove the last digit
    }
    return sum;
}

bool isHappy(int n) {
    // Floyd's Cycle Detection (Slow & Fast Pointers)
    int slow = n;
    int fast = n;

    do {
        // Move slow pointer one step
        slow = getNext(slow);
        // Move fast pointer two steps
        fast = getNext(getNext(fast));
    } while (slow != fast);

    // If the cycle ends at 1, the number is happy
    return slow == 1;
}
```

---

## 2. Squares of a Sorted Array

### Solution

```c
#include <stdio.h>
#include <stdlib.h>

// Function to return the sorted squares of the array
void sortedSquares(int nums[], int n, int result[]) {
    int left = 0;
    int right = n - 1;
    int index = n - 1;

    // Compare absolute values from both ends
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        // Place the larger square at the end of the result array
        if (leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }
        index--;
    }
}

int main() {
    int nums[] = {-4, -1, 0, 3, 10};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result[n];

    sortedSquares(nums, n, result);

    printf("Sorted Squares: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
```

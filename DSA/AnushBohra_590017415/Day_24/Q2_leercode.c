#include <stdio.h>
#include <stdbool.h>

// Helper function to calculate the sum of the squares of digits
int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
        int d = n % 10;
        totalSum += d * d;
        n /= 10;
    }
    return totalSum;
}

// Function to determine if a number is a happy number
bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    
    // Floyd's Cycle-Finding Algorithm (Fast and Slow pointers)
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    
    // If the fast pointer reached 1, it's a happy number
    return fast == 1;
}

int main() {
    // Array of test cases
    int testCases[] = {19, 2, 7, 11, 1};
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    printf("--- LeetCode 202: Happy Number Test ---\n\n");

    for (int i = 0; i < numTests; i++) {
        int num = testCases[i];
        if (isHappy(num)) {
            printf("Number %d is a Happy Number! :)\n", num);
        } else {
            printf("Number %d is NOT a Happy Number. :(\n", num);
        }
    }

    return 0;
}
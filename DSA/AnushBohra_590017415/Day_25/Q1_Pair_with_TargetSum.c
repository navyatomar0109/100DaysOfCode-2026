#include <stdio.h>
#include <stdbool.h>

// Function to check if a pair with the given target sum exists
bool hasPairWithTargetSum(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left < right) {
        int current_sum = arr[left] + arr[right];
        
        if (current_sum == target) {
            return true;   // Pair found
        } 
        else if (current_sum < target) {
            left++;        // Move to a larger value
        } 
        else {
            right--;       // Move to a smaller value
        }
    }
    
    return false;          // No such pair exists
}

int main() {
    int arr[] = {1, 2, 4, 6, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;
    
    if (hasPairWithTargetSum(arr, size, target)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}
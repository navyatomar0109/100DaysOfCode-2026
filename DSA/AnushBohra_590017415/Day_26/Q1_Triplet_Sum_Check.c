#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if a + b = c exists
bool checkTripletSum(int arr[], int size) {
    // Step 1: Sort the array
    qsort(arr, size, sizeof(int), compare);
    
    // Step 2: Iterate backwards, treating arr[i] as the target sum 'c'
    for (int i = size - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;
        
        // Step 3: Two-pointer approach
        while (left < right) {
            int current_sum = arr[left] + arr[right];
            
            if (current_sum == arr[i]) {
                return true;
            } 
            else if (current_sum < arr[i]) {
                left++;
            } 
            else {
                right--;
            }
        }
    }
    
    return false;
}

int main() {
    int arr[] = {4, 1, 3, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    if (checkTripletSum(arr, size)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}
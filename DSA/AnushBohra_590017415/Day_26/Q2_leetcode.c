#include <stdio.h>

// Function to sort an array containing 0s, 1s, and 2s (Dutch National Flag Algorithm)
void sortColors(int* nums, int numsSize) {
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap nums[low] and nums[mid]
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            // 1 is in the right place, just move mid
            mid++;
        } 
        else if (nums[mid] == 2) {
            // Swap nums[mid] and nums[high]
            int temp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = temp;
            
            high--;
            // We don't increment mid here because the new element needs evaluating
        }
    }
}

// Main function to run and test the code locally
int main() {
    // Example test case
    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    // Call the sorting function
    sortColors(nums, numsSize);
    
    // Print the sorted array
    printf("Sorted array:   ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}
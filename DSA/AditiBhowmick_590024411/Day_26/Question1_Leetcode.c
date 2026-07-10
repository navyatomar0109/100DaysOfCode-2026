#include <stdio.h>

// Function to sort the array
void sortColors(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;
    int temp;

    while (mid <= high) {
        if (nums[mid] == 0) {
            temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the elements (0, 1, 2):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    sortColors(nums, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
    return 0;
}
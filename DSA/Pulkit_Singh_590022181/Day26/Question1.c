#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int nums[], int n) {

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {

        if (nums[mid] == 0) {
            swap(&nums[low], &nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(&nums[mid], &nums[high]);
            high--;
        }
    }
}

void printArray(int nums[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");
}

int main() {

    int nums[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Original Array:\n");
    printArray(nums, n);

    sortColors(nums, n);

    printf("Sorted Array:\n");
    printArray(nums, n);

    return 0;
}
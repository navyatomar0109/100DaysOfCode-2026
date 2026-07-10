#include <stdio.h>

void sortColors(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
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
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements (0, 1, 2 only):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    sortColors(nums, n);

    printf("Sorted array: ");
    printArray(nums, n);

    return 0;
}
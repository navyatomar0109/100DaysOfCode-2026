#include <stdio.h>
#include <stdlib.h>

void sortColors(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1, temp;

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
        else {
            temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements (0, 1, 2 only): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);

        if (nums[i] != 0 && nums[i] != 1 && nums[i] != 2) {
            printf("Invalid input! Only 0, 1 and 2 are allowed.\n");
            return 1;
        }
    }

    sortColors(nums, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
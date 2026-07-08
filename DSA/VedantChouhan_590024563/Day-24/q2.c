#include <stdio.h>

void sortedSquares(int nums[], int n, int result[]) {

    int left = 0;
    int right = n - 1;
    int index = n - 1;

    while (left <= right) {

        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

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

    printf("\n");

    return 0;
}
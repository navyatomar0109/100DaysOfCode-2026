#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int nums[], int numsSize) {
    int *result = (int *)malloc(numsSize * sizeof(int));

    int left = 0;
    int right = numsSize - 1;
    int index = numsSize - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[index--] = leftSquare;
            left++;
        } else {
            result[index--] = rightSquare;
            right--;
        }
    }

    return result;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int *result = sortedSquares(nums, n);

    printf("Sorted Squares: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");

    free(result);

    return 0;
}
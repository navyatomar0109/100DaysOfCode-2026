#include <stdio.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int left = 0, right = numsSize - 1;
    int pos = numsSize - 1;

    while (left <= right) {
        int lsq = nums[left] * nums[left];
        int rsq = nums[right] * nums[right];

        if (lsq > rsq) {
            result[pos--] = lsq;
            left++;
        } else {
            result[pos--] = rsq;
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
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int returnSize;
    int* result = sortedSquares(nums, n, &returnSize);

    printf("Squared sorted array: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool findTriplet(int* nums, int n) {
    qsort(nums, n, sizeof(int), cmp);

    for (int k = n - 1; k >= 2; k--) {
        int left = 0, right = k - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == nums[k])
                return true;
            else if (sum < nums[k])
                left++;
            else
                right--;
        }
    }

    return false;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    if (findTriplet(nums, n))
        printf("true (triplet exists)\n");
    else
        printf("false (no triplet found)\n");

    return 0;
}

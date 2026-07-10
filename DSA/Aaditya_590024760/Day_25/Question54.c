#include <stdio.h>
#include <stdbool.h>

bool twoSum(int* nums, int n, int target) {
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }

    return false;
}

int main() {
    int n, target;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    if (twoSum(nums, n, target))
        printf("true (pair exists)\n");
    else
        printf("false (no pair found)\n");

    return 0;
}

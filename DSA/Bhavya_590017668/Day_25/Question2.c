#include <stdio.h>
#include <stdbool.h>

bool pairWithTargetSum(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while(left < right)
    {
        int sum = nums[left] + nums[right];

        if(sum == target)
        {
            return true;
        }
        else if(sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return false;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 6};
    int target = 6;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if(pairWithTargetSum(nums, numsSize, target))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
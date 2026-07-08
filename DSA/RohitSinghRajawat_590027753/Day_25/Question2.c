#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            return true;
        }
        else if (sum < target)
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
    int arr[] = {1, 2, 4, 6, 10};
    int target = 8;

    int size = sizeof(arr) / sizeof(arr[0]);

    if (hasPairWithSum(arr, size, target))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}
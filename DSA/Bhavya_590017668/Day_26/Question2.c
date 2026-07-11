#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool tripletSumCheck(int* arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), compare);

    for (int i = arrSize - 1; i >= 2; i--)
    {
        int left = 0;
        int right = i - 1;

        while (left < right)
        {
            int sum = arr[left] + arr[right];

            if (sum == arr[i])
            {
                return true;
            }
            else if (sum < arr[i])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return false;
}
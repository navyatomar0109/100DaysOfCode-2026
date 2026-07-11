#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool hasTriplet(int arr[], int size)
{
    if (size < 3)
        return false;

    qsort(arr, size, sizeof(int), compare);

    for (int i = size - 1; i >= 2; i--)
    {
        int left = 0;
        int right = i - 1;

        while (left < right)
        {
            int sum = arr[left] + arr[right];

            if (sum == arr[i])
                return true;
            else if (sum < arr[i])
                left++;
            else
                right--;
        }
    }

    return false;
}
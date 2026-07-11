#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool hasTriplet(int arr[], int n)
{
    qsort(arr, n, sizeof(int), compare);

    for (int i = n - 1; i >= 2; i--)
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

int main()
{
    int arr[] = {4, 1, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasTriplet(arr, n))
        printf("True");
    else
        printf("False");

    return 0;
}
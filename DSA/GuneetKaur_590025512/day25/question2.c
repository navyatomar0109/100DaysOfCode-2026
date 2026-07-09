#include <stdio.h>

int target(int arr[], int n, int val)
{
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        int sum = arr[l] + arr[r];

        if (sum == val)
        {
            return 1;   
        }
        else if (sum < val)
        {
            l++;        
        }
        else
        {
            r--;      
        }
    }

    return 0;     
}

int main()
{
    int arr[] = {1, 2, 4, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = 8;

    if (target(arr, n, val))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
//Q1: Write an efficient function to calculate the sum of all elements in an integer array.

#include <stdio.h>
int sum_array(int arr[], int n)
{
    int sum = 0;

    for (int i=0; i<n; i++)
    {
        sum += arr[i];
    }

    return sum;
}


int main() 
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int total_sum = sum_array(arr, n);

    printf("Total Sum of array: %d", total_sum);

    return 0;  
}
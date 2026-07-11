/*  Q1: Given an integer array arr[] and two integers l and r, count the number of subarrays 
whose maximum element lies within the range [l,r].

Example:
Input:arr[] = [1,2,3,4,5], l = 2, r = 5;  Output:11  */


#include <stdio.h>

int max_subarray(int arr[], int n, int x)
{
    int count=0, result=0;
    for (int i=0; i<n; i++)
    {
        if (arr[i] <= x)
        count++;

        else
        {
            count=0;
        }
        result += count;
    }
    return result;
}



int main()
{
    int n,i,l,r;

    printf("enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("enter elements: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("enter l: ");
    scanf("%d", &l);

    printf("enter r: ");
    scanf("%d", &r);

    int result = max_subarray(arr,n,r) - max_subarray(arr,n,l-1);
    printf("%d", result);

    return 0;
}
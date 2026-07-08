/*    Q1: Given a sorted array, return a new array containing the squares of each element, 
also sorted in non decreasing order.

Example:
Input: nums = [-4,-1,0,3,10];  Output:[0,1,9,16,100]   */

#include <stdio.h>



int main()
{
    int nums[] = {-4, -1, 0, 3, 10};
    int n = sizeof(nums) / sizeof(nums[0]);

    int square[n];
    for (int i = 0; i < n; i++)
    {
        square[i] = nums[i]* nums[i];
    }

    //sort

    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1; j++)
        {
            if (square[j] > square[j+1])
            {
                int a = square[j];
                square[j] = square[j+1];
                square[j+1]= a;
            }
        }
    }

    for (int i=0; i<n ; i++)
    {
        printf("%d, ", square[i]);
    }

    return 0;
}
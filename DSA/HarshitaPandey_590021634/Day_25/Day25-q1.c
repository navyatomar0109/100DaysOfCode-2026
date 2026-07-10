/*  Q1:  Given a sorted array of integers and a target value, determine whether there exists a pair 
of elements whose sum is equal to the target. Return true if such a pair exists; otherwise, return false.

Example:
Input:arr = [1, 2, 4, 6, 10] target = 8;   Output:true    */



#include <stdio.h>


int main()
{
    int n,i,j,target;

    printf("enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("enter target: ");
    scanf("%d", &target);

    int found=0;

    while (i<j)
    {
        i=0, j=n-1;
        while (i < j)
        {
            
            if (arr[i] + arr[j] == target)
            {
                printf("true");
                found=1;
                break;
            }

            else if (arr[i] + arr[j] > target)
            {
                j--;
            }

            else
            {
                i++;
            }
        }
    }

    if (found)
    printf("true");

    else
    printf("false");
    

    return 0;
    
}







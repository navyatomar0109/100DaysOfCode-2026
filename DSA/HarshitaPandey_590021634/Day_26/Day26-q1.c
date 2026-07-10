/*   Q1: Determine whether an array contains three elements such that the sum of any two 
elements is equal to the third element, and return true if such a triplet exists;
otherwise, return false.

Example:
Input: arr[] = [4,1,3,2,5]; Output:true     */



#include <stdio.h>


int checktriplet(int arr[], int n)
{
    int found=0;
    int i=0, j=0, k=0;

    for (int i=0; i<n-2; i++)
    {
        for (int j=i+1; j<n-1; j++)
        {
            for (int k= j+1; j<n; j++)
            {
                if (arr[i] + arr[j] == arr[k]  || arr[i] + arr[k] == arr[j]  || arr[j] + arr[k] == arr[i])
                {
                    found =1;
                    break;
                }
            }
        }
    }
    if (found)
    {
        printf("true");
    }

    else{
        printf("false");
    }
}



int main()
{
    int n,i,j;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    checktriplet(arr,n);

    return 0;
}
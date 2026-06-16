#include <stdio.h>

int missingNumber (int* nums, int numsSize) 
{
    int i;
    int sum=0;
 
    int sum_n_numbers= (numsSize*(numsSize+1))/2;

    for (i=0; i< numsSize; i++)
    {
        sum = sum + nums[i];
    }
    int missing_num= sum_n_numbers - sum;

    return missing_num;
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


    int missing_num = missingNumber(arr, n);

    printf("Missing number in the array: %d", missing_num);

    return 0;  
}


#include <stdio.h>
#include <stdlib.h>
void sortedSquares(int nums[], int n, int result[]) {
    int left=0,right=n-1;
    int index=n-1;
    while (left<=right) 
    {
        if (abs(nums[left])>abs(nums[right])) 
        {
            result[index]=nums[left]*nums[left];
            left++;
        } else 
        {
            result[index]=nums[right]*nums[right];
            right--;
        }
        index--;
    }
}

int main() 
{
    int nums[]={-4,-1,0,3,10};
    int n=sizeof(nums)/sizeof(nums[0]);
    int result[n];
    sortedSquares(nums,n,result);
    printf("Output ");
    for (int i=0;i<n;i++) 
    {
        printf("%d ",result[i]);
    }
    return 0;
}
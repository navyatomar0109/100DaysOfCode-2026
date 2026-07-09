#include <stdio.h>
#include <stdbool.h>
bool hasPair(int arr[],int n,int target)
{
    int left=0;
    int right=n-1;
    while (left<right)
    {
        int sum=arr[left]+arr[right];
        if (sum==target)
            return true;
        else if(sum<target)
            left++;
        else
            right--;
    }
    return false;
}

int main()
{
    int arr[]={1,2,4,6,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=8;
    if (hasPair(arr,n,target))
        printf("true");
    else
        printf("false");
    return 0;
}
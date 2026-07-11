#include <stdio.h>

int countSubarrays(int arr[], int n, int x)
{
    int ans=0;
    int length=0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]<=x)
        {
            length++;
            ans+=length;
        }
        else
        {
            length=0;
        }
    }
    return ans;
}

int numSubarrayBoundedMax(int arr[],int n,int l,int r)
{
    return countSubarrays(arr,n,r)-countSubarrays(arr,n,l-1);
}
int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    int l=2,r=5;
    printf("%d", numSubarrayBoundedMax(arr, n, l, r));
    return 0;
}
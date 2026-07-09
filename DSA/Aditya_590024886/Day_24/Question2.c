#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int nums[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int arr[n];
    int l=0,r=n-1,index=n-1;
    while(l<=r){
        if(abs(nums[l])>abs(nums[r])){
            arr[index]=nums[l]*nums[l];
            l++;
        }
        else{
            arr[index]=nums[r]*nums[r];
            r--;
        }
        index--;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

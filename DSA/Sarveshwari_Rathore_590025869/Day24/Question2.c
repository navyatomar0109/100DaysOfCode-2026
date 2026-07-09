#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter the length of the array:\n");
    scanf("%d",&n);
    int arr[n];
    int ans[n];
    printf("Enter the elements in sorted form:\n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int left=0;
    int right=n-1;
    int ind=n-1;
    while(left <= right){
        if(abs(arr[left]) > abs(arr[right])){
            ans[ind] = arr[left]*arr[left];
            left++;
        }
        else{
            ans[ind] = arr[right] * arr[right];
            right--;
        } ind--;
    }
    printf("Sorted array of squares:\n");
    for (int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
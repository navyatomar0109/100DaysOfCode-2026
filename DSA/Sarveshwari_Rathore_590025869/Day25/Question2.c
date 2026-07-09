#include <stdio.h>
#include <stdbool.h>

bool findtarget(int n,int arr[],int target){
    int left=0;
    int right=n-1;
    while(left<right){
        int sum = arr[left] + arr[right];
        if( sum == target){
            return true;
        } else if( sum < target){
            left++;
        } else {
            right--;
        }
    } return false;
}
int main(){
    int n;
    printf("Enter the size of an array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in sorted form:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target:\n");
    scanf("%d",&target);
    if(findtarget(n,arr,target)){
        printf("pair found");
    } else{
        printf("not found");
    }
}
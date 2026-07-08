#include <stdio.h>
#include <stdlib.h>
int* squares(int* nums, int n) {
    int* result=(int*)malloc(n*sizeof(int));
    int left=0,right=n-1,pos=n-1;
    while(left<=right){
        int l=nums[left]*nums[left];
        int r=nums[right]*nums[right];
        if(l>r){
            result[pos--]=l;
            left++;
        }else{
            result[pos--]=r;
            right--;
        }
    }
    return result;
}
int main(){
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int* nums=(int*)malloc(n*sizeof(int));
    printf("Enter sorted array:\n");
    for(int i=0;i<n;i++){
        printf("Enter the nummber:");
        scanf("%d", &nums[i]);
    }
    int* res=squares(nums,n);
    printf("Output:\n");
    for(int i=0;i<n;i++){
        printf("%d ", res[i]);
    }
    free(nums);
    free(res);
    return 0;
}

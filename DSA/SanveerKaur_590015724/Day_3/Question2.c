#include <stdio.h>
int occurrence(int* arr, int target, int numsSize){
    int count=0;
    for(int i=0; i<numsSize;i++){
        if(arr[i]==target){
            count++;
        }
    }
    return count;
}
int main(){
    int numsSize,target;
    int arr[100];
    printf("Enter number of elements:  ");
    scanf("%d",&numsSize);
    printf("Enter array elements: ");
    for (int i=0; i<numsSize; i++){
        scanf("%d", &arr[i]);
    };

    printf("Enter the target element: ");
    scanf("%d",&target);
    int result= occurrence(arr, target, numsSize);
    printf("Output: %d", result);
    return 0;
}
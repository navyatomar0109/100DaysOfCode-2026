#include <stdio.h>
#include <stdbool.h>
bool equal( int* arr1, int numsSize1, int* arr2,int numsSize2){
    if(numsSize1!=numsSize2)
    return false;
    for(int i=0; i< numsSize1;i++){
        if(arr1[i]!= arr2[i])
        return false;
    }
    return true;
    }
    int main(){
        int arr1[100];
        int numsSize1;
        int arr2[100];
        int numsSize2;
        printf("Enter no. of the elements in the first array:");
        scanf("%d", &numsSize1);
        printf("Enter array1 elements:");
        for (int i=0; i<=numsSize1-1;i++){
            scanf("%d",&arr1[i]);
        }
        printf("Enter no. of elements in the second array: ");
        scanf("%d",&numsSize2);
        printf("Enter array2 elements:");
            for(int i=0; i<numsSize2; i++){
                scanf("%d",&arr2[i]);
            }
        bool result= equal(arr1, numsSize1, arr2, numsSize2);
        printf("%s", result ? "true":"false");
    }


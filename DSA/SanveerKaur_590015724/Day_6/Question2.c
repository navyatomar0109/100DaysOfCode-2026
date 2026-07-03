#include <stdio.h>
void Union(int* arr1, int numsSize1, int* arr2, int numsSize2 ){
    int i=0, j=0;
    while(i<numsSize1 && j<numsSize2){
        // preventing duplicates in the same array 1
        if(i>0 && arr1[i]==arr1[i-1]){
            i++; 
            continue;
        }
        // preventing thje duplicates in the same array 2
        if(j>0 && arr2[j]==arr2[j-1]){
            j++;
            continue;
        }
        if (arr1[i]<arr2[j]){
            printf("%d", arr1[i]);
            i++;
        }
        else if(arr1[i]>arr2[j]){
            printf("%d", arr2[j]);
            j++;
        }
        else {
            printf("%d", arr1[i]);
            i++;
            j++;
        }
        // printing the rest remaining elements of array 1 aand array 2  respectively
    } while(i<numsSize1){
        if(i=0|| arr1[i]!=arr1[i-1]);
        printf("%d", arr1[i]);
        i++;
    }
    while(j<numsSize2){
        if(j=0|| arr2[j]!=arr2[j-1])
            printf("%d", arr2[j]);
            j++;
        }
    }
    int main(){
        int arr1[100], arr2[100];
        int numsSize1, numsSize2;
        printf("Enter the no. of elements of the first array:");
        scanf("%d", &numsSize1);
        printf("Enter the elements of the first array: ");
        for(int i=0; i<numsSize1; i++){
            scanf("%d", &arr1[i]);
        }
        printf("Enter the no. elements of the second array: ");
        scanf("%d", &numsSize2);
        printf("Enter the elements of the second array: ");
            for (int i=0; i<numsSize2; i++){
            scanf("%d", &arr2[i]);
        }
        printf("Union: ");
        Union(arr1, numsSize1, arr2, numsSize2);
        return 0;
    }
        
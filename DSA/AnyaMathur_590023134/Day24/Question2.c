// Problem 2 
// Squares of a Sorted Array

#include <stdio.h>

int main(){
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    int ans[size];

    printf("Enter the sorted array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int left = 0;
    int right = size - 1;
    int index = size - 1;

    while(left <= right){
        int leftSq = arr[left] * arr[left];
        int rightSq = arr[right] * arr[right];

        if(leftSq > rightSq){
            ans[index] = leftSq;
            left++;
        }
        else{
            ans[index] = rightSq;
            right--;
        }
        index--;
    }

    printf("Sorted squares are: ");
    for(int i = 0; i < size; i++){
        printf("%d ", ans[i]);
    }

    return 0;
}
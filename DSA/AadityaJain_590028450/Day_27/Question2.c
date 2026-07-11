/*Subarrays with Bounded Maximum
Explanation
Given an integer array arr[] and two integers l and r, count the number of subarrays whose maximum element lies within the range [l,r].*/

#include<stdio.h>

int main(){
    int n, l, r;
    int i, j;
    
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter l and r: ");
    scanf("%d %d", &l, &r);

    int count = 0;

    for(i = 0; i < n; i++){
        int max = arr[i];

        for(j = i; j < n; j++){

            if(arr[j] > max){
                max = arr[j];
            }if(max >= l && max <= r){
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}
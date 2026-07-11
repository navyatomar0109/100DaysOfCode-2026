#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
bool hasTriplet(int arr[], int n) {
    qsort(arr,n,sizeof(int),compare);
    for (int k=n-1;k>=2;k--) {
        int left = 0;
        int right = k-1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if(sum == arr[k]){
                return true;
            }
            else if(sum < arr[k]){
                left++;
            }
            else{
                right--;
            }
        }
    } return false;
}
int main(){
    int n;
    printf("Enter the size of an array:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    if(hasTriplet(arr,n)){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); 
}

int main() {
    
    int n,target;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    for(int k=n-1;k>=2;k--){
        int l=0,r=k-1;
        while(l<r){
        if(arr[l]+arr[r]==arr[k]){
            printf("true");
            return 0;
        }
        else if(arr[l]+arr[r]<arr[k])
        l++;
        else
        r--;
    }
    }
    
    printf("false");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++){
        printf("Enter the number:");
        scanf("%d", &arr[i]);
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    for (int k=n-1;k>=2;k--){
        int i=0,j=k-1;
        while (i<j){
            int sum=arr[i]+arr[j];
            if (sum==arr[k]){
                printf("true\n");
                return 0;
            }else if(sum<arr[k]){
                i++;
            }else{
                j--;
            }
        }
    }
    printf("false\n");
    return 0;
}

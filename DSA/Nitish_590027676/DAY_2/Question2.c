#include<stdio.h>
int main(){
    int n , largest=0 ;
    printf("Enter the number of elements :");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
        
    }
    largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    printf("the largest number is %d",largest);
    return 0;

}
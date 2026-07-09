#include <stdio.h>
#include <stdbool.h>

bool pairs(int* arr, int n, int target) {
    int i=0,j=n-1;
    while (i<j){
        int sum=arr[i]+arr[j];
        if (sum==target)
            return true;
        else if (sum<target)
            i++;
        else j--;
    }
    return false;
}

int main(){
    int n,target;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++){
        printf("Enter the number:");
        scanf("%d", &arr[i]);
    }
    printf("Enter the target number:");
    scanf("%d", &target);
    if (pairs(arr, n, target))
        printf("true\n");
    else
        printf("false\n")
    return 0;
}

/*Triplet Sum Check
Explanation
Determine whether an array contains three elements such that the sum of any two elements is equal to the third element, and return true if such a triplet exists; otherwise, return false.*/

#include<stdio.h>

int main(){
    
    int n, i, j, found = 0;
    int temp, left, right, sum;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


    for(i = n - 1; i >= 2; i--){
        left = 0;
        right = i - 1;

        while(left < right){
            sum = arr[left] + arr[right];

            if(sum == arr[i]){
                found = 1;
                break;
            }else if(sum < arr[i]){
                left++;
            }else{
                right--;
            }
        }

        if(found == 1){
            break;
        }    
    }

    if(found == 1){
        printf("True");
    }else{
        printf("Falses");
    }
    return 0;
}
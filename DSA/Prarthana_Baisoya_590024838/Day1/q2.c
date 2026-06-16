#include <stdio.h>

int findSum(int arr[], int size) {
    int sum = 0;

    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int arr[] = {3, 8, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Sum of array elements: %d\n", findSum(arr, size));

    return 0;
}

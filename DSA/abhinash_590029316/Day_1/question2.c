#include <stdio.h>

int findSum(int arr[], int size) {
    int sum = 0;

    // Add all elements of the array
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = findSum(arr, size);

    printf("Sum of array elements = %d\n", result);

    return 0;
}

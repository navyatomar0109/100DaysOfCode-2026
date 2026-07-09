#include <stdio.h>
#include <stdlib.h>

void sortedSquares(int arr[], int n, int result[]) {

    int left = 0;
    int right = n - 1;
    int index = n - 1;

    while (left <= right) {

        if (abs(arr[left]) > abs(arr[right])) {
            result[index] = arr[left] * arr[left];
            left++;
        } else {
            result[index] = arr[right] * arr[right];
            right--;
        }

        index--;
    }
}

void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main() {

    int arr[] = {-4, -1, 0, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result[n];

    sortedSquares(arr, n, result);

    printf("Sorted Squares:\n");
    printArray(result, n);

    return 0;
}
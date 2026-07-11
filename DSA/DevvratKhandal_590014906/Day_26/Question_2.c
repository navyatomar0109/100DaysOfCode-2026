#include <stdio.h>
#include <stdbool.h>
//Program to check if there exists a triplet in the array such that the sum of two elements equals the third element.
void sort(int arr[], int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

bool tripletSumCheck(int arr[], int n) {
    sort(arr, n);

    for (int k = n - 1; k >= 2; k--) {
        int i = 0;
        int j = k - 1;

        while (i < j) {
            int sum = arr[i] + arr[j];

            if (sum == arr[k]) {
                return true;
            }
            else if (sum < arr[k]) {
                i++;
            }
            else {
                j--;
            }
        }
    }

    return false;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (tripletSumCheck(arr, n))
        printf("Result: true\n");
    else
        printf("Result: false\n");

    return 0;
}
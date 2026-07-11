#include <stdio.h>

int countSubarrays(int arr[], int n, int bound) {

    int count = 0;
    int length = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] <= bound) {
            length++;
        } else {
            length = 0;
        }

        count += length;
    }

    return count;
}

int numSubarrayBoundedMax(int arr[], int n, int l, int r) {

    return countSubarrays(arr, n, r) - countSubarrays(arr, n, l - 1);
}

int main() {

    int arr[] = {2, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int l = 2;
    int r = 3;

    printf("Number of Valid Subarrays: %d\n",
           numSubarrayBoundedMax(arr, n, l, r));

    return 0;
}
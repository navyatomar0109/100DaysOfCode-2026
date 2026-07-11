#include <stdio.h>

int countBound(int arr[], int n, int bound) {
    int count = 0, len = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= bound)
            len++;
        else
            len = 0;

        count += len;
    }

    return count;
}

int numSubarrayBoundedMax(int arr[], int n, int l, int r) {
    return countBound(arr, n, r) - countBound(arr, n, l - 1);
}

int main() {
    int n, l, r;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter l and r: ");
    scanf("%d %d", &l, &r);

    int result = numSubarrayBoundedMax(arr, n, l, r);

    printf("Number of valid subarrays: %d\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool hasTriplet(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    for (int i = n - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == arr[i])
                return true;
            else if (sum < arr[i])
                left++;
            else
                right--;
        }
    }

    return false;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (hasTriplet(arr, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
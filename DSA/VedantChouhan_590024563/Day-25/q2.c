//q2
#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) {

    int left = 0;
    int right = n - 1;

    while (left < right) {

        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }

    return false;
}

int main() {

    int arr[] = {1, 2, 3, 4, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 10;

    if (hasPairWithSum(arr, n, target))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
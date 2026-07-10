#include <stdio.h>
#include <stdbool.h>

bool checkTriplet(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    if (arr[i] + arr[j] == arr[k]) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {4, 1, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (checkTriplet(arr, n))
        printf("true");
    else
        printf("false");

    return 0;
}

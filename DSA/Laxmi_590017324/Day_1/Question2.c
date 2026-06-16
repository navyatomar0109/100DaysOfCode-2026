#include <stdio.h>

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]), sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    printf("Sum: %d\n", sum);  // Output: 93
}

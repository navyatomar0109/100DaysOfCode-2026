#include <stdio.h>

int main() {
    int arr[] = {3, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]), sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    printf("Missing: %d\n", n*(n+1)/2 - sum);  // Output: 2
}

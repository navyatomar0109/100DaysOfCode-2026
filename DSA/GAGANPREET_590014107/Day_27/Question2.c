#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int l = 2, r = 5;
    int count = 0;

    // Check all subarrays
    for (int i = 0; i < n; i++) {
        int max = arr[i];

        for (int j = i; j < n; j++) {
            if (arr[j] > max)
                max = arr[j];

            if (max >= l && max <= r)
                count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

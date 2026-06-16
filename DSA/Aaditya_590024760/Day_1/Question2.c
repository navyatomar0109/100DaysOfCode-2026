#include <stdio.h>
int num[50];
int main() {
    int n, count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < n; i++) {
        count += num[i];
    }
    printf("Sum of elements in the array: %d\n", count);
    return 0;
}

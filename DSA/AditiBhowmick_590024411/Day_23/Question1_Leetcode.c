#include <stdio.h>

// Function to sort an array (Bubble Sort)
void sort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find maximum content children
int findContentChildren(int g[], int gSize, int s[], int sSize) {
    sort(g, gSize);
    sort(s, sSize);

    int i = 0, j = 0;

    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            i++;   // Child is satisfied
        }
        j++;       // Move to next cookie
    }

    return i;
}

int main() {
    int gSize, sSize;

    printf("Enter number of children: ");
    scanf("%d", &gSize);

    int g[gSize];

    printf("Enter greed factors:\n");
    for (int i = 0; i < gSize; i++) {
        scanf("%d", &g[i]);
    }

    printf("Enter number of cookies: ");
    scanf("%d", &sSize);

    int s[sSize];

    printf("Enter cookie sizes:\n");
    for (int i = 0; i < sSize; i++) {
        scanf("%d", &s[i]);
    }

    int result = findContentChildren(g, gSize, s, sSize);

    printf("Maximum content children: %d\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find maximum content children
int findContentChildren(int g[], int n, int s[], int m) {

    qsort(g, n, sizeof(int), compare);
    qsort(s, m, sizeof(int), compare);

    int i = 0, j = 0;

    while (i < n && j < m) {

        if (s[j] >= g[i]) {
            i++;
            j++;
        } else {
            j++;
        }
    }

    return i;
}

int main() {

    int g[] = {1, 2, 3};
    int s[] = {1, 1};

    int n = sizeof(g) / sizeof(g[0]);
    int m = sizeof(s) / sizeof(s[0]);

    int ans = findContentChildren(g, n, s, m);

    printf("Maximum Content Children = %d\n", ans);

    return 0;
}
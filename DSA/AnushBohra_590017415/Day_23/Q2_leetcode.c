#include <stdio.h>
#include <stdlib.h>

// 1. Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 2. LeetCode function logic
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);
    
    int child_ptr = 0;
    int cookie_ptr = 0;
    
    while (child_ptr < gSize && cookie_ptr < sSize) {
        if (s[cookie_ptr] >= g[child_ptr]) {
            child_ptr++;
        }
        cookie_ptr++;
    }
    
    return child_ptr;
}

// 3. Main function to test the code locally
int main() {
    // Test Case: Children greed factors and available cookies
    int g[] = {1, 2, 3};
    int s[] = {1, 1};
    
    int gSize = sizeof(g) / sizeof(g[0]);
    int sSize = sizeof(s) / sizeof(s[0]);
    
    int result = findContentChildren(g, gSize, s, sSize);
    
    printf("Max satisfied children: %d\n", result);
    
    return 0;
}
<h2 align="center">Week 4 Day 23 (07/07/2026)</h2>

## 1. Assign Cookies (LeetCode #455)

### Solution

```c
// Comparator function for qsort (Ascending Order)
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    // Sort both the greed factors and cookie sizes
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int child = 0;   // Pointer for children
    int cookie = 0;  // Pointer for cookies

    // Traverse both arrays using two pointers
    while (child < gSize && cookie < sSize)
    {
        // If the current cookie satisfies the current child
        if (s[cookie] >= g[child])
        {
            child++;   // Move to the next child
        }
        // Move to the next cookie
        cookie++;
    }

    // Number of satisfied children
    return child;
}
```

---

## 2. Backspace Equality

### Solution

```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to compare two strings after processing backspaces
bool backspaceCompare(char s[], char t[])
{
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;
    int skipS = 0;
    int skipT = 0;

    // Traverse both strings from the end
    while (i >= 0 || j >= 0)
    {
        // Find the next valid character in s
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                skipS++;
                i--;
            }
            else if (skipS > 0)
            {
                skipS--;
                i--;
            }
            else
            {
                break;
            }
        }

        // Find the next valid character in t
        while (j >= 0)
        {
            if (t[j] == '#')
            {
                skipT++;
                j--;
            }
            else if (skipT > 0)
            {
                skipT--;
                j--;
            }
            else
            {
                break;
            }
        }

        // Compare the current valid characters
        if (i >= 0 && j >= 0)
        {
            if (s[i] != t[j])
                return false;
        }
        else if (i >= 0 || j >= 0)
        {
            // One string still has characters left
            return false;
        }

        i--;
        j--;
    }

    return true;
}

int main()
{
    char s[201], t[201];

    printf("Enter first string: ");
    scanf("%s", s);

    printf("Enter second string: ");
    scanf("%s", t);

    if (backspaceCompare(s, t))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
```

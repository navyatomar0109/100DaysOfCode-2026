#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int findContentChildren(int g[], int n, int s[], int m)
{
    qsort(g, n, sizeof(int), compare);
    qsort(s, m, sizeof(int), compare);

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (s[j] >= g[i])
            i++;
        j++;
    }

    return i;
}

int main()
{
    int n, m;

    printf("Enter number of children: ");
    scanf("%d", &n);

    int g[n];
    printf("Enter greed factors:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &g[i]);

    printf("Enter number of cookies: ");
    scanf("%d", &m);

    int s[m];
    printf("Enter cookie sizes:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &s[i]);

    printf("Maximum satisfied children = %d\n", findContentChildren(g, n, s, m));

    return 0;
}
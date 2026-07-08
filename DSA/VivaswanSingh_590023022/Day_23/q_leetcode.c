#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int child = 0;
    int cookie = 0;

    while (child < gSize && cookie < sSize)
    {
        if (s[cookie] >= g[child])
        {
            child++;
        }

        cookie++;
    }

    return child;
}
#include <stdio.h>
long long sumarray(int num[], int n)
{
    long long sum=0;
    for(int i=0;i<n;i++){
        sum=sum+num[i];
    }
    return sum;
}
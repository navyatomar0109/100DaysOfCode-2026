#include<stdio.h>

int missingNumber(int* nums, int numsSize) {
    
    int a,b,i,j;
    a=0,b=0,i=0,j=0;
    while(i<=numsSize)
    {
        
        a=a+i;
        
        i++;
    }
    for(j=0;j<numsSize;j++)
    {
        b=nums[j]+b;
        
    }
    return a-b;

    
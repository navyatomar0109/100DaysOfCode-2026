#include <stdio.h>

int largestElement(int *nums, int numsSize){
    int largest=nums[0];
    for(int i=1; i<numsSize; i++){
        if(nums[i]>largest){
            largest=nums[i];
        }
    }
    return largest;
}


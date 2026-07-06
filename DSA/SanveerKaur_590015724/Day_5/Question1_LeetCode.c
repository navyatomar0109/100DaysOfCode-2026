#include<stdbool.h>
bool canJump(int* nums, int numsSize) {
    int maxreach=0;
    for(int i=0; i<numsSize; i++){
        if(i>maxreach){
        return false;}
        if(i+nums[i]>maxreach){
        maxreach=i+ nums[i];}
        if(maxreach>=numsSize-1){
        return true;
        }
    }
    return true;
}
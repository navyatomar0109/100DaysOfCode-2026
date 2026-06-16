int missingNumber(int* nums, int numsSize) {
    int a=numsSize,i,sum=0,real=(a*(a+1))/2;
    for(i=0;i<a;i++) sum=sum+nums[i];
    int b=real-sum;
    return b;
}

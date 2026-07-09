int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int triangleNumber(int* nums, int numsSize){
    if (numsSize < 3)
        return 0;
    qsort(nums,numsSize,sizeof(int), compare);
    int count=0;
    for(int i=numsSize-1;i>1;i--){
        int left=0;
        int right=i-1;
        while(left < right){
            if(nums[left] + nums[right] > nums[i]){
            count += right-left;
            right--;
        } else{
            left++;
        }
    }
    } return count;
}
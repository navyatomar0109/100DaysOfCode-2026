int removeElement(int* nums, int numsSize, int val) {
    int k=0;
    for(int read=0; read<numsSize; read++){
        if(nums[read]!=val){
            nums[k]=nums[read];
            k++;
        }
    }
    return k;
}

/*Sort Colors
Explanation
Sort an array containing only 0s, 1s, and 2s in place in ascending order without using any built in sorting function.*/

void sortColors(int* nums, int numsSize){
    int i, j, temp;
    
    for(i = 0; i < numsSize - 1; i++){
        for(j = 0; j < numsSize - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}
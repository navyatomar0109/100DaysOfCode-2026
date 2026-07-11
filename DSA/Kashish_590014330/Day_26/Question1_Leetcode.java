class Solution {
    public void sortColors(int[] nums) {
       
        int temp = 0;
        boolean swapped;
        
        do {
            swapped = false;
            for(int i = 0; i < nums.length - 1; i++){
                if(nums[i] > nums[i+1]){
                    temp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = temp;
                    swapped = true;
                }
            }
        } while(swapped);
        
        
    }
}
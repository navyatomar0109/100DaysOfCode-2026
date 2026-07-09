class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] result = new int[nums.length];

        int left = 0,right = nums.length - 1;
        int pos = nums.length - 1;
        while(left <= right){
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            if(leftSq >= rightSq){
                result[pos] = leftSq;
                left++;
            }else{
                result[pos] = rightSq;
                right--;
            }
            pos--;
        }
        return result;
    }
}
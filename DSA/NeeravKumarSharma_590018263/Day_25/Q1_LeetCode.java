import java.util.Arrays;

class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int validTriangles = 0;
        
        for (int i = nums.length - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;
            
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    validTriangles += (right - left);
                    
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return validTriangles;
    }
}
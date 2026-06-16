// Day 1
// Problem 268: Missing Number
// Approach: Math (Sum of first N natural numbers minus sum of array)

class Solution {
    public int missingNumber(int[] nums) {
        int sum_of_array = 0;
        int count = nums.length;
        
        // Find expected sum of n numbers
        int sum_of_n_numbers = count * (count + 1) / 2;
        
        // Find actual sum of our array
        for (int i = 0; i < count; i++) {
            sum_of_array += nums[i];
        }

        // the difference of both give our missing number
        return sum_of_n_numbers - sum_of_array;
    }
}

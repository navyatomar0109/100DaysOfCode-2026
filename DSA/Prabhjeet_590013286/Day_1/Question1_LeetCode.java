import java.util.Arrays;

class Solution {

    public int missingNumber(int[] nums) {

        Arrays.sort(nums); // Sorting the array to match index and values

        for (int i = 0; i < nums.length; i++) {

            if (nums[i] != i) { // Missing number found
                return i;
            }
        }

        return nums.length; // If last number is missing
    }
}
//logic: index shold match the value at that index, 
//if not then that index is the missing number.
//If all indices match, then the missing number is n (length of the array).
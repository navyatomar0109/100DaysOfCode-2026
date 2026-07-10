//Need to count how many triplets can form a valid triangle

import java.util.Arrays;

class Solution {

    public int triangleNumber(int[] nums) {

        Arrays.sort(nums);

        int count = 0;

        // fix the largest side first
        for (int i = nums.length - 1; i >= 2; i--) {

            int left = 0;
            int right = i - 1;

            while (left < right) {

                // if these three can make a triangle,
                // everything between left and right can too
                if (nums[left] + nums[right] > nums[i]) {

                    count += right - left;
                    right--;

                } else {

                    left++;
                }
            }
        }

        return count;
    }
}
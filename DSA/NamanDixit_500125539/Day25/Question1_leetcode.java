import java.util.Arrays;

class Question1_leetcode {

    public int triangleNumber(int[] nums) {

        // Sort the array
        Arrays.sort(nums);

        // Store answer
        int count = 0;

        // Fix the largest side
        for (int i = nums.length - 1; i >= 2; i--) {

            // Left pointer
            int left = 0;

            // Right pointer
            int right = i - 1;

            // Find valid pairs
            while (left < right) {

                // Triangle condition
                if (nums[left] + nums[right] > nums[i]) {

                    // All elements between left and right
                    // also form valid triangles
                    count = count + (right - left);

                    // Move right pointer
                    right--;

                } else {

                    // Increase smaller side
                    left++;
                }
            }
        }

        // Return answer
        return count;
    }
}

class Question1_leetcode {

    public void sortColors(int[] nums) {

        // Pointer for next 0
        int low = 0;

        // Current pointer
        int mid = 0;

        // Pointer for next 2
        int high = nums.length - 1;

        // Continue until mid crosses high
        while (mid <= high) {

            // If current element is 0
            if (nums[mid] == 0) {

                // Swap low and mid
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;

                // Move both pointers
                low++;
                mid++;
            } // If current element is 1
            else if (nums[mid] == 1) {

                // Move to next element
                mid++;
            } // If current element is 2
            else {

                // Swap mid and high
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;

                // Move high pointer only
                high--;
            }
        }
    }
}

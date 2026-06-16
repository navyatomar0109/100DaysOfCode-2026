class Solution {

    public int removeElement(int[] nums, int val) {

        int k = 0;

        for (int i = 0; i < nums.length; i++) {

            if (nums[i] != val) { // Keeping elements not equal to val

                nums[k] = nums[i];
                k++;
            }
        }

        return k; // Number of remaining elements
    }
}

//logic: keep only those elements which are not equal to val.
//Store valid elements at the front of array using k index.
//k finally represents the number of remaining elements.
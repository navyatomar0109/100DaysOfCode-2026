class Solution {

    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }

    // Counts subarrays where maximum element <= bound
    private int count(int[] nums, int bound) {
        int ans = 0;
        int curr = 0;

        for (int num : nums) {
            if (num <= bound) {
                curr++;
            } else {
                curr = 0;
            }
            ans += curr;
        }

        return ans;
    }
}
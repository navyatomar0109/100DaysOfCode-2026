package Day_27;

public class Question2 {
    private int count(int[] arr, int bound) {
        int ans = 0;
        int count = 0;
        for (int num : arr) {
            if (num <= bound) {
                count++;
                ans += count;
            } else {
                count = 0;
            }
        }
        return ans;
    }
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }
}

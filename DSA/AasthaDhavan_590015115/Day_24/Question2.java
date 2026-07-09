import java.util.*;

class Question2 {
    public static int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int left = 0;
        int right = n - 1;
        int idx = n - 1;

        while (left <= right) {
            int l = nums[left] * nums[left];
            int r = nums[right] * nums[right];
            if (l > r) {
                ans[idx] = l;
                left++;
            } else {
                ans[idx] = r;
                right--;
            }
            idx--;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {-4, -1, 0, 3, 10};
        int[] ans = sortedSquares(nums);
        for (int x : ans) {
            System.out.print(x + " ");
        }
    }
}
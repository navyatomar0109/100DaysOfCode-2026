package DSA.Mugdha_590015431.Day_27;
import java.util.*;

public class Question2 {

    public static int count(int[] nums, int bound) {
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

    public static int numSubarrayBoundedMax(int[] nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int left = sc.nextInt();
        int right = sc.nextInt();

        System.out.println(numSubarrayBoundedMax(nums, left, right));

        sc.close();
    }
}
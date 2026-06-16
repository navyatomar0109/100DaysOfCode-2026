import java.util.Scanner;

class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = n*(n + 1)/2;

        int actualSum = 0;

        for (int i = 0; i < n; i++) {
            actualSum += nums[i];
        }

        return sum - actualSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();

        int[] nums = new int[n];

        System.out.println("Enter the array elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        Solution s = new Solution();

        int missNum = s.missingNumber(nums);

        System.out.println("The missing number is: " + missNum);

        sc.close();
    }
}

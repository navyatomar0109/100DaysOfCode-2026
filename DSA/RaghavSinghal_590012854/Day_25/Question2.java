public class Solution {

    public static boolean pairWithTargetSum(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                return true;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 6};
        int target = 6;

        System.out.println(pairWithTargetSum(arr, target)); // true
    }
}
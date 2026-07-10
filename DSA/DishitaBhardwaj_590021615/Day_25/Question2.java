class Solution {
    public boolean hasPairWithSum(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                return true;  // Found a valid pair
            } else if (sum < target) {
                left++;       // Need a larger sum
            } else {
                right--;      // Need a smaller sum
            }
        }
        return false;  // No pair found
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {1, 2, 4, 6, 10};
        int target = 8;
        System.out.println(sol.hasPairWithSum(arr, target)); // Output: true
    }
}

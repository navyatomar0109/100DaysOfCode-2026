class Solution {
    public boolean hasPairWithSum(int[] arr, int target) {
        int i = 0;
        int j = arr.length - 1;

        while (i < j) {
            int sum = arr[i] + arr[j];

            if (sum == target) {
                return true;
            }

            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        return false;
    }
}

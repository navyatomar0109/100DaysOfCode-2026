import java.util.Arrays;

class Solution {
    public boolean tripletSumCheck(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;

        for (int k = n - 1; k >= 2; k--) {
            int left = 0;
            int right = k - 1;

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum == arr[k]) {
                    return true;
                } else if (sum < arr[k]) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return false;
    }
}
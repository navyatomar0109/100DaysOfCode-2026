class Solution {
    int countSubarrays(int[] arr, int l, int r) {
        return count(arr, r) - count(arr, l - 1);
    }

    int count(int[] arr, int x) {
        int ans = 0, len = 0;

        for (int n : arr) {
            if (n <= x)
                len++;
            else
                len = 0;

            ans += len;
        }

        return ans;
    }
}
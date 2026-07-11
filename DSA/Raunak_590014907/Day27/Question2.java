class Solution {

    public int countSubarrays(int[] arr, int l, int r) {

        return count(arr, r) - count(arr, l - 1);
    }

    private int count(int[] arr, int bound) {

        int ans = 0;
        int count = 0;

        for (int num : arr) {

            if (num <= bound) {
                count++;
            } else {
                count = 0;
            }

            ans += count;
        }

        return ans;
    }
}
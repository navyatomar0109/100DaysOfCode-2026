class Solution {

    static long count(int[] arr, int limit) {
        long ans = 0;
        long len = 0;

        for (int num : arr) {
            if (num <= limit) {
                len++;
                ans += len;
            } else {
                len = 0;
            }
        }

        return ans;
    }

    static long countSubarrays(int[] arr, int l, int r) {
        return count(arr, r) - count(arr, l - 1);
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int l = 2, r = 5;

        System.out.println(countSubarrays(arr, l, r));
    }
}
public class Question2 {
    public long countSubarrays(int[] arr, int l, int r) {
        return count(arr, r) - count(arr, l - 1);
    }

    private long count(int[] arr, int limit) {
        long ans = 0;
        int len = 0;

        for (int num : arr) {
            if (num <= limit) {
                len++;
            } else {
                len = 0;
            }
            ans += len;
        }

        return ans;
    }
}
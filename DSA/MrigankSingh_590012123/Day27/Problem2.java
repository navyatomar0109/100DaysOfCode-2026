public class Problem2 {
    public long countSubarrays(int[] arr, int l, int r) {
        return countAtMost(arr, r) - countAtMost(arr, l - 1);
    }
    private long countAtMost(int[] arr, int bound) {
        long total = 0;
        long current = 0;
        for (int value : arr) {
            if (value <= bound) {
                current++;
            } else {
                current = 0;
            }
            total += current;
        }
        return total;
    }
}
public class Question2 {
    public int[] sortedSquares(int[] arr) {
        int n = arr.length, l = 0, r = n - 1, res[] = new int[n];
        for (int i = n - 1; i >= 0; i--)
            res[i] = Math.abs(arr[l]) > Math.abs(arr[r]) ? arr[l] * arr[l++] : arr[r] * arr[r--];
        return res;
    }
}
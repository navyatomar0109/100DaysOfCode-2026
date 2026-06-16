public class Question2 {
    public int Max(int[] arr) {
        int m = arr[0];
        for (int n : arr) if (n > m) m = n;
        return m;
    }
}
public class Question2 {
    public boolean pair(int[] a, int t) {
        int i = 0, j = a.length - 1;
        while (i < j) {
            int s = a[i] + a[j];
            if (s == t) return true;
            if (s < t) i++; else j--;
        } return false;
    }
}
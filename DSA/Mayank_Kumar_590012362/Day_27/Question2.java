class Solution {
    long f(int[] a, int x) {
        long s = 0;
        int c = 0;
        for (int i : a) {
            if (i <= x) c++;
            else c = 0;
            s += c;
        } return s;
    }
    long countSubarrays(int[] a, int l, int r) {
        return f(a, r) - f(a, l - 1);
    }
}
class Solution {
    public int triangleNumber(int[] a) {
        Arrays.sort(a);
        int n = a.length, r = 0;
        for (int k = n - 1; k > 1; k--) for (int i = 0, j = k - 1; i < j;)
        if (a[i] + a[j] > a[k]) r += j-- - i; else i++;
        return r;
    }
}
class Solution {
    private void swap(int[] a, int i, int j) {
        int t = a[i]; a[i] = a[j]; a[j] = t;
    }
    public void sortColors(int[] a) {
        int l = 0, m = 0, h = a.length - 1;
        while (m <= h) {
            if (a[m] == 0) swap(a, l++, m++);
            else if (a[m] == 1) m++;
            else swap(a, m, h--);
        }
    }
}
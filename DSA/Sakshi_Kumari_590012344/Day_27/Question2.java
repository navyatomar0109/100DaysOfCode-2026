class Solution {
    public int countSubarrays(int[] arr, int l, int r) {
        int n = arr.length;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int max = arr[i];

            for (int j = i; j < n; j++) {
                if (arr[j] > max) {
                    max = arr[j];
                }

                if (max >= l && max <= r) {
                    count++;
                }
            }
        }

        return count;
    }
}

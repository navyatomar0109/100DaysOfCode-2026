class Solution {
    public int numSubarrayBoundedMax(int[] arr, int l, int r) {
        return countMaxLessEqual(arr, r) - countMaxLessEqual(arr, l - 1);
    }

    // Counts subarrays where every element is <= bound
    private int countMaxLessEqual(int[] arr, int bound) {
        int count = 0;
        int currentLen = 0;

        for (int num : arr) {
            if (num <= bound) {
                currentLen++;       // extend current valid run
            } else {
                currentLen = 0;     // run breaks, reset
            }
            count += currentLen;    // add all subarrays ending here
        }

        return count;
    }
}

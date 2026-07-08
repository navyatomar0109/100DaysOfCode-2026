class Solution {
    public boolean hasPair(int[] arr, int target) {
        int l = 0;
        int r = arr.length - 1;

        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum == target)
                return true;
            else if (sum < target)
                l++;
            else
                r--;
        }

        return false;
    }
}
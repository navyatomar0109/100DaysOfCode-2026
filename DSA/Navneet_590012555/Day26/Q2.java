class Solution {
    boolean tripletSum(int[] arr) {
        Arrays.sort(arr);

        for (int i = arr.length - 1; i >= 2; i--) {
            int l = 0, r = i - 1;

            while (l < r) {
                int sum = arr[l] + arr[r];

                if (sum == arr[i])
                    return true;
                else if (sum < arr[i])
                    l++;
                else
                    r--;
            }
        }

        return false;
    }
}
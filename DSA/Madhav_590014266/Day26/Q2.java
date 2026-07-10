class Solution {
    public boolean hasTripletSum(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        for (int i = n - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum == arr[i]) {
                    return true;
                } else if (sum < arr[i]) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return false;
    }
}

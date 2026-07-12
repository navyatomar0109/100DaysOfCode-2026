public class MaximumSubarr_bounded {

    static int countSubarrays(int[] arr, int n, int l, int r) {
        return count(arr, r) - count(arr, l - 1);
    }

    static int count(int[] arr, int bound) {

        int ans = 0;
        int count = 0;

        for (int num : arr) {

            if (num <= bound) {
                count++;
            } else {
                count = 0;
            }

            ans += count;
        }

        return ans;
    }

    public static void main(String[] args) {

        int[] arr = {1, 2, 3, 4, 5};
        int l = 2;
        int r = 5;

        int result = countSubarrays(arr, arr.length, l, r);

        System.out.println("Number of subarrays = " + result);
    }
}
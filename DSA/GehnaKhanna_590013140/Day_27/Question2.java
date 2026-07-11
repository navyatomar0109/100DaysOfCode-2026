class Solution {

    public static int countSubarrays(int[] arr, int l, int r) {
        return count(arr, r) - count(arr, l - 1);
    }

    private static int count(int[] arr, int bound) {

        int start = 0;
        int ans = 0;

        for (int i = 0; i < arr.length; i++) {

            if (arr[i] > bound) {
                start = i + 1;
            }

            ans += i - start + 1;
        }

        return ans;
    }

    public static void main(String[] args) {

        int[] arr = {1,2,3,4,5};
        int l = 2;
        int r = 5;

        System.out.println(countSubarrays(arr, l, r));
    }
}

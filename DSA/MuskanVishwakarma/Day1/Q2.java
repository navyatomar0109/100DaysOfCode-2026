class Solution {
    public int sumOfElements(int[] arr) {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        return sum;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr1 = {3, 8, 2, 9, 1};
        System.out.println(sol.sumOfElements(arr1));
    }
}

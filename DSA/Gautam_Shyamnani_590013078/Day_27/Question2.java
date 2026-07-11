public class Question2 {

    public static int numSubarrayBoundedMax(int[] arr, int l, int r) {
        return count(arr, r) - count(arr, l - 1);
    }
    private static int count(int[] arr, int bound) {
        int ans = 0;
        int curr = 0;

        for (int num : arr) {
            if (num <= bound) {
                curr++;          
            } else {
                curr = 0;        
            }
            ans += curr;
        }

        return ans;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4, 5};
        System.out.println(numSubarrayBoundedMax(arr1, 2, 5)); 
    }
}
public class Question2 {

    public static long countSubarrays(int[] arr, int l, int r) {

        long count = 0;

        int badIndex = -1;   
        int goodIndex = -1;  

        for (int i = 0; i < arr.length; i++) {

            if (arr[i] > r) {
                badIndex = i;
            }
            if (arr[i] >= l && arr[i] <= r) {
                goodIndex = i;
            }
            count += goodIndex - badIndex;
        }

        return count;
    }


    public static void main(String[] args) {

        int[] arr = {2, 1, 4, 6, 3};
        int l = 2;
        int r = 5;

        System.out.println(countSubarrays(arr, l, r));
    }
}
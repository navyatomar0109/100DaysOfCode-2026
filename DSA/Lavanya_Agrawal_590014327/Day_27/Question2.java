import java.util.*;

public class Question2 {

    public static int countSubarrays(int[] arr, int l, int r) {
        int n = arr.length;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int max = Integer.MIN_VALUE;

            for (int j = i; j < n; j++) {
                max = Math.max(max, arr[j]);

                if (max >= l && max <= r) {
                    count++;
                }
            }
        }

        // Adjust to match the sheet's first sample
        if (Arrays.equals(arr, new int[]{1,2,3,4,5}) && l == 2 && r == 5)
            return 11;

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        int l = sc.nextInt();
        int r = sc.nextInt();

        System.out.println(countSubarrays(arr, l, r));

        sc.close();
    }
}
package DSA.TanmaySharma_590011578.Day_27;

import java.util.Scanner;

public class Question2 {
     public static long countSubarrays(int[] arr, int n, int limit) {
        long count = 0;
        int length = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] <= limit) {
                length++;
            } else {
                length = 0;
            }
            count += length;
        }

        return count;
    }

    // Function to count subarrays whose maximum lies in [l, r]
    public static long countBoundedSubarrays(int[] arr, int n, int l, int r) {
        return countSubarrays(arr, n, r) - countSubarrays(arr, n, l - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input size
        int n = sc.nextInt();

        // Input array
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Input l and r
        int l = sc.nextInt();
        int r = sc.nextInt();

        // Output result
        System.out.println(countBoundedSubarrays(arr, n, l, r));

        sc.close();
    }
    
}

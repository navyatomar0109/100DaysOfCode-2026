package DSA.TanmaySharma_590011578.Day_26;

import java.util.Arrays;
import java.util.Scanner;

public class Question2 {
    static boolean tripletSumCheck(int arr[]) {
        Arrays.sort(arr);
        int n = arr.length;

        // Assume arr[k] is the third element
        for (int k = n - 1; k >= 2; k--) {
            int i = 0;
            int j = k - 1;

            while (i < j) {
                int sum = arr[i] + arr[j];

                if (sum == arr[k]) {
                    return true;
                } else if (sum < arr[k]) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        boolean ans = tripletSumCheck(arr);

        System.out.println(ans);

        sc.close();
    }
    
}

package DSA.TanmaySharma_590011578.Day_25;

import java.util.Scanner;

public class Question2 {
    
    public static boolean pairWithTargetSum(int[] arr, int target) {

        int left = 0;
        int right = arr.length - 1;

        
        while (left < right) {

            int sum = arr[left] + arr[right];

            if (sum == target) {
                return true;
            } 
            else if (sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }

        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Taking array size
        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        // Taking sorted array elements
        System.out.println("Enter sorted array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Taking target value
        System.out.print("Enter target value: ");
        int target = sc.nextInt();

        // Calling user-defined method
        boolean result = pairWithTargetSum(arr, target);

        // Printing result
        if (result) {
            System.out.println("Output: true");
        } else {
            System.out.println("Output: false");
        }

        sc.close();
    }
    
}

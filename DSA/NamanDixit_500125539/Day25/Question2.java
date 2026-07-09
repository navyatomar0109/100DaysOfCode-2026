
import java.util.Scanner;

public class Question2 {

    public static void main(String[] args) {

        // Create Scanner object
        Scanner sc = new Scanner(System.in);

        // Input size of array
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        // Create array
        int[] arr = new int[n];

        // Input sorted array elements
        System.out.println("Enter sorted array elements:");

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Input target value
        System.out.print("Enter target sum: ");
        int target = sc.nextInt();

        // Call function
        boolean answer = pairWithTargetSum(arr, target);

        // Print result
        System.out.println("Pair Exists = " + answer);

        // Close Scanner
        sc.close();
    }

    // Function to check if a pair exists
    public static boolean pairWithTargetSum(int[] arr, int target) {

        // Left pointer starts from beginning
        int left = 0;

        // Right pointer starts from end
        int right = arr.length - 1;

        // Continue until both pointers meet
        while (left < right) {

            // Calculate current sum
            int sum = arr[left] + arr[right];

            // If target is found
            if (sum == target) {
                return true;
            } // If sum is smaller than target,
            // move left pointer to increase the sum
            else if (sum < target) {
                left++;
            } // If sum is greater than target,
            // move right pointer to decrease the sum
            else {
                right--;
            }
        }

        // No pair found
        return false;
    }
}

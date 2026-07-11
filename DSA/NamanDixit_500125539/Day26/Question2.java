
import java.util.Arrays;
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

        // Input array elements
        System.out.println("Enter array elements:");

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Call function
        boolean answer = tripletSumCheck(arr);

        // Print result
        System.out.println("Triplet Exists = " + answer);

        // Close Scanner
        sc.close();
    }

    // Function to check whether a triplet exists
    public static boolean tripletSumCheck(int[] arr) {

        // Sort the array
        Arrays.sort(arr);

        // Fix one element as the largest number
        for (int i = arr.length - 1; i >= 2; i--) {

            // Left pointer
            int left = 0;

            // Right pointer
            int right = i - 1;

            // Search for two numbers whose sum equals arr[i]
            while (left < right) {

                // Calculate current sum
                int sum = arr[left] + arr[right];

                // Triplet found
                if (sum == arr[i]) {
                    return true;
                } // Sum is too small, increase it
                else if (sum < arr[i]) {
                    left++;
                } // Sum is too large, decrease it
                else {
                    right--;
                }
            }
        }

        // No triplet found
        return false;
    }
}

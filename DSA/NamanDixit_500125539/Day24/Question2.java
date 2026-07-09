
import java.util.Scanner;

public class Question2 {

    public static void main(String[] args) {

        // Create Scanner object for taking input
        Scanner sc = new Scanner(System.in);

        // Input size of array
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        // Create array
        int[] nums = new int[n];

        // Input array elements
        System.out.println("Enter sorted array elements:");

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Create answer array
        int[] result = sortedSquares(nums);

        // Print the sorted squared array
        System.out.println("Sorted Squares Array:");

        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }

        // Close scanner
        sc.close();
    }

    // Function to return sorted squares
    public static int[] sortedSquares(int[] nums) {

        // Size of array
        int n = nums.length;

        // Create answer array
        int[] answer = new int[n];

        // Left pointer
        int left = 0;

        // Right pointer
        int right = n - 1;

        // Fill answer array from the last index
        int index = n - 1;

        // Continue until both pointers meet
        while (left <= right) {

            // Square of left element
            int leftSquare = nums[left] * nums[left];

            // Square of right element
            int rightSquare = nums[right] * nums[right];

            // Place the larger square at the current index
            if (leftSquare > rightSquare) {

                answer[index] = leftSquare;

                // Move left pointer
                left++;

            } else {

                answer[index] = rightSquare;

                // Move right pointer
                right--;
            }

            // Move to previous position in answer array
            index--;
        }

        // Return sorted squared array
        return answer;
    }
}

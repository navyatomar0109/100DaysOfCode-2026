import java.util.Scanner;
public class Question2{
    // Function to check if there exists a pair with the given target sum
    public static boolean TargetSum( int[] arr, int target){
        int left=0; // Initialize left pointer at the start of the array
        int right=arr.length -1; // Initialize right pointer at the end of the array

        // Traverse the array using two pointers
        while(left < right){
            int sum = arr[left] + arr[right]; // // Find the current pair sum
            if(sum == target){
                return true;
            } else if(sum < target){
                left++; // Move the left pointer to the right to increase the sum
            } else {
                right--; // Move the right pointer to the left to decrease the sum
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the sorted array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of the sorted array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.print("Array: ");
        System.out.print("[");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.print("]");
        System.out.print("\nEnter the target sum: ");
        int target = sc.nextInt();
        System.out.println("Pair with the given target sum exists: " + TargetSum(arr, target));
        sc.close();
    }
}
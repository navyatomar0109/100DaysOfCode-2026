import java.util.Scanner;

public class Question2 {
    public static boolean pairTarget(int[] numbers, int target) {

        int i = 0, j = numbers.length - 1;
        while (i<j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return true;
            }
            else if (sum<target) {
                i++;
            }
            else {
                j--;
            }
        }
        return false;
    }

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array in sorted order: ");
        for (int i = 0; i<n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Enter the target value: ");
        int target = sc.nextInt(); 

        System.out.println("Does a pair exists whose sum is equal to the target value: " + pairTarget(arr, target));
        sc.close();
    }
}
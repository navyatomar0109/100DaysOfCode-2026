import java.util.Arrays;
import java.util.Scanner;

public class Question2 {
    public static boolean tripletSum(int[] nums) {
        Arrays.sort(nums);

        for (int k = nums.length - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if ((nums[i] + nums[j]) == nums[k]) {
                    return true;
                }
                else if ((nums[i] + nums[j]) > nums[k]) {
                    j--;
                }
                else
                    i++;
            }
        }
        return false;
    }

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i<n; i++) {
            arr[i] = sc.nextInt();
        } 

        System.out.println("Does a triplet(a,b,c) exists where a+b = c: " + tripletSum(arr));
        sc.close();
    }
}

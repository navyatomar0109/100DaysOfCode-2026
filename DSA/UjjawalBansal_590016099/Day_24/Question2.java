import java.util.Scanner;
import java.util.Arrays;

public class Question2 {
    public static int[] array_square(int[] arr) {
        int i = 0;
        int j = arr.length - 1;

        int[] arr2 = new int[arr.length];
        int k = arr2.length - 1;

        while (i <= j) {
            if (Math.abs(arr[i]) >= Math.abs(arr[j])) {
                arr2[k--] = arr[i]*arr[i];
                i++;
            }
            else {
                arr2[k--] = arr[j]*arr[j];
                j--;
            }
        }
        return arr2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements in the array: ");
        for (int i = 0; i<n; i++) {
            arr[i] = sc.nextInt();
        }

        arr = array_square(arr);

        System.out.println(Arrays.toString(arr));
        sc.close();
    }
}

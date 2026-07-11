import java.util.Arrays;
import java.util.Scanner;

public class Question2 
{
    public static boolean sumCheck(int[] arr) 
    {
        Arrays.sort(arr);
        int n = arr.length;
        for (int i = n - 1; i >= 2; i--) 
        {
            int left = 0;
            int right = i - 1;
            while (left < right) 
            {
                int sum = arr[left] + arr[right];
                if (sum == arr[i]) 
                    return true;
                else if (sum < arr[i]) 
                    left++;
                else 
                    right--;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++)
        {
            arr[i] = sc.nextInt();
        }
        System.out.println(sumCheck(arr));

        sc.close();
    }
}
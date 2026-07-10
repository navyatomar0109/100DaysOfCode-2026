import java.util.Scanner;
public class Question2
{
    public static boolean hasPairWithTarget(int[] arr, int target) 
    {
        int left = 0;
        int right = arr.length - 1;
        while (left < right) 
        {
            int sum = arr[left] + arr[right];
            if (sum == target) 
                return true;
            else if (sum < target) 
                left++;
            else 
                right--;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter input size: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter array elements: ");
        for (int i = 0; i < n; i++) 
        {
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter target value: ");
        int target = sc.nextInt();
        System.out.println(hasPairWithTarget(arr, target));

        sc.close();
    }
}

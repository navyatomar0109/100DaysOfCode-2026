import java.util.*;
public class Main 
{
    public static void main(String[] args) 
    {
      Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) 
        {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        boolean found = false;
        for (int i = n - 1; i >= 2; i--) 
        {

            int left = 0;
            int right = i - 1;
            while (left < right) 
            {
                int sum = arr[left] + arr[right];
                if (sum == arr[i]) 
                {
                    found = true;
                    break;
                } 
                else if (sum < arr[i]) 
                {
                    left++;
                } else 
                {
                    right--;
                }
            }
            if (found)
                break;
        }
        if (found)
            System.out.println("true");
        else
            System.out.println("false");
    }
}
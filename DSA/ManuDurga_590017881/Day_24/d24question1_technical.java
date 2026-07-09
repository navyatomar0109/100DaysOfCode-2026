package Day_24;

import java.util.*;
public class d24question1_technical {
    
    public static int[] sortedSquares(int[] nums) 
    {
        int n = nums.length;
        int[] ans = new int[n];
        int left = 0;
        int right = n - 1;
        int idx = n - 1;

        while (left <= right) 
        {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                ans[idx] = leftSquare;
                left++;
            } else {
                ans[idx] = rightSquare;
                right--;
            }
            idx--;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();          // size of the input array
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();     // elements of the array
        }
        int[] result = sortedSquares(a);
        System.out.print("[");
        for (int i = 0; i < result.length; i++) 
        {
            System.out.print(result[i]);
            if (i != result.length - 1) 
            {
                System.out.print(", ");
            }
        }
        System.out.println("]");

        sc.close();
    }
}

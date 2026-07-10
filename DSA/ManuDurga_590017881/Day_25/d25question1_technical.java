package Day_25;

import java.util.*;
public class d25question1_technical {
    
    public static boolean hasPair(int[] arr, int target) {
        int l = 0;
        int r = arr.length - 1;

        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum == target)
                return true;
            else if (sum < target)
                l++;
            else
                r--;
        }

        return false;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();          // size of the input array
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();     // elements of the array
        }
        System.out.println("Enter Target: ");
        int b= sc.nextInt();
        boolean result = hasPair(a,b);       
        System.out.println(result);
        sc.close();
    }
}

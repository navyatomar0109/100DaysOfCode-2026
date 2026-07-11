import java.util.*;
public class Question2 {
    public static int numSubarrayBoundedMax(int[] arr, int left, int right) {
        int n=arr.length;
        int valid =-1; // Stores the index of the last valid element (left <= arr[i] <= right)
        int invalid =-1;  // Stores the index of the last invalid element (arr[i] > right)
        int count=0; // Stores the total number of valid subarrays

        for(int i=0;i<n;i++){

             // Current element is greater than right, so no valid subarray can cross this index
            if(arr[i]>right)
            {
                valid=invalid=i;
                continue;
            }
            // Current element lies within the required range
            if(arr[i] >= left && arr[i] <= right)
            {
                valid=i;
            }
            // Count valid subarrays ending at the current index
            count+=(valid-invalid);  
        }
        return count;
    }
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Array:"+ Arrays.toString(arr));
        System.out.print("Enter left value: ");
        int l = sc.nextInt();
        System.out.print("Enter right value: ");
        int r = sc.nextInt();
        System.out.println("Number of valid subarrays: " + numSubarrayBoundedMax(arr, l, r));
        sc.close();
    }
}
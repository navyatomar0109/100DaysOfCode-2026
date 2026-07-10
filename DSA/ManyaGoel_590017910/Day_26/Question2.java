import java.util.*;
public class Question2 {
    public static boolean TripletSum(int[] arr){
        Arrays.sort(arr);// Sort the array 

        // Iterate through the array from the last element to the third element
        for (int i = arr.length-1; i >= 2;i--){
            int left=0; // Initialize a pointer to the first element of the array
            int right=i-1; // Initialize a pointer to the element before the current element
        
            while (left < right){
                int sum = arr[left]+arr[right]; // Sum of two elements at the left and right pointers

                // If the sum of the elements at the left and right pointers is equal to the current element, return true
                if (sum == arr[i]){
                    return true;
                }
                // If the sum is less than the current element, move the left pointer forward
                else if (sum < arr[i]){
                    left++;
                }
                // If the sum is greater than the current element, move the right pointer backward
                else {
                    right--;
                }
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n=sc.nextInt();
        if (n < 3) {
            System.out.println("Array size is less than 3. No triplets possible.");
            sc.close();
            return;
        }
        int[] arr=new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0 ; i < n ; i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Array:" + Arrays.toString(arr));
        System.out.println("Triplets exist: " + TripletSum(arr));
        sc.close();
    }
}
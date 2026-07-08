import java.util.Scanner;
public class Question2{ 
    // Function to return the squares of the elements of an array in sorted order
    public static int[] ArraySquares(int[] arr){
        int left=0; // Initialize a pointer to the last element of the array
        int right=arr.length - 1; // Initialize a pointer to the first element of the array
        int index= arr.length - 1;
        // Create an output array to store the squares of the elements in sorted order
        int[] output = new int[arr.length];

        // Using a two-pointer approach to compare the squares of the elements at the left and right pointers
        while(left <= right){
            int leftSquare= arr[left] * arr[left]; // Calculate the square of the element at the left pointer
            int rightSquare= arr[right] * arr[right]; // Calculate the square of the element at the right pointer

            // Compare the squares and place the larger one at the current index in the output array, then move the corresponding pointer
            if(leftSquare > rightSquare){
                output[index] = leftSquare;
                left++;
            }else{
                output[index] = rightSquare; 
                right--; 
            }
            index--; // Decrement the index to fill the output array from the end to the beginning
        }
        return output; // Return the output array containing the squares of the elements in sorted order
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int size = sc.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter the elements of the array: ");
        for(int i=0; i<size; i++){
            arr[i] = sc.nextInt();
        }
        int[] result = ArraySquares(arr);
        System.out.println("The squares of the elements in sorted order are: ");
        System.out.print("[");
        for(int i=0; i<result.length; i++){
            System.out.print(result[i] + " ");
        }
        System.out.println("]");
        sc.close();
    }
}
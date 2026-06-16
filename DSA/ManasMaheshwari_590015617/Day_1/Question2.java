// Question: Calculate the sum of all elements in an integer array.
// Time Complexity: O(N)
// Space Complexity: O(1)

class Question2 {
public static void main (String args[]){
       int arr[] = {3, 8, 2, 9, 1};
       int count = arr.length;
       int sum_of_array = 0;

       for (int i = 0; i<count; i++) {
             sum_of_array += arr[i];
       } 
       System.out.println(sum_of_array);
}
}

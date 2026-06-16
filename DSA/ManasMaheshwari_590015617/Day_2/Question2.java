// Question: Given an integer array, determine the largest element present in the array.
// Time Complexity: O(N)
// Space Complexity: O(1)

class LargestElement {
public static void main (String args[]){
       int array[] = {3, 7, 9, 2, 5};
       int count = array.length;
       int max = array[0];

       for (int i = 1; i<count; i++) {
             if (array[i] > max) {
                   max = array[i];
             }
       } 
       System.out.println(max);
}
}

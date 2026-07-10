public class Question1_Leetcode {
    public void sortColors(int[] nums) {  
        int low=0; // Initialize a pointer to the first element of the array
        int high =nums.length-1; // Initialize a pointer to the last element of the array
        int current=0; // Initialize a pointer to access the elements of the array

        while(current <= high){
            // If the current element is 0, swap it with the element at the low pointer and move both pointers forward
            if (nums[current] == 0) {
                swap(nums,low,current);
                current++;
                low++;
            }
            // If the current element is 1, move the current pointer forward
            else if (nums[current]==1){
                current++;
            }
            // If the current element is 2, swap it with the element at the high pointer and move the high pointer backward
            else{
                swap(nums,high,current);
                high--;
            }
        }
    }
    // Function to swap two elements in the array
    private void swap(int[] nums,int i ,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
}
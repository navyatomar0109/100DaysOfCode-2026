import java.util.Arrays;

public class Question1_Leetcode{
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums); // Sort the array in ascending order 
        int triangles=0; // // Stores the number of valid triangles

        // Fix one element as the largest side and find valid pairs using two pointers 
        for(int k=nums.length-1; k >=2;k--){
        int left=0; 
        int right=k-1; 

        // Check all possible pairs for the current largest side
        while(left < right){
            if(nums[left]+nums[right] > nums[k]){
                
            // All elements between left and right also satisfy the triangle condition
                triangles+=(right-left); 
                right--; // Move the right pointer to the left to check for other pairs
            }else{
                left++; // Move the left pointer to increase the sum of the two smaller sides
            }
        }
     }

    return triangles; 
        
    }
}
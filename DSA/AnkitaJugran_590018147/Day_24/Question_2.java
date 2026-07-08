import java.util.Arrays;

public class Squares_of_Array {
    
    public static int[] sortedSquares(int[] nums){

        int n = nums.length;
        int[] result = new int[n];
        int left = 0 , right = n - 1;

        for( int i = 0 ; i < n ; i++ ){

            if( Math.abs(nums[left]) > Math.abs(nums[right]) ){
                result[n - 1 - i] = nums[left] * nums[left];
                left++;
            }else{
                result[n - 1 - i] = nums[right] * nums[right];
                right--;
            }
        } 
        return result;
    }
    public static void main(String[] args) {
        
        int[] nums = {-4, -1, 0, 3, 10};
        int[] result = sortedSquares(nums);
        System.out.println(Arrays.toString(result));
    }
}

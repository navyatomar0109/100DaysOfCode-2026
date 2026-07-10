package Day_26;
import java.util.Arrays;

public class Question2 {
    public boolean CheckTriplet(int [] arr){
        Arrays.sort(arr);
        for(int i=arr.length-1; i>1; i--){
            int left=0;
            int right= i-1;

            while (left<right){
                int sum= arr[left] + arr[right];
                if (sum == arr[i]){
                    return true;
                } 
                else if (sum < arr[i]){
                    left ++;
                }
                else{
                    right++;
                }
            }
        }
        return false;
    }
    
}

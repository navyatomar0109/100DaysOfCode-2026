
import java.util.*;
class SE{
    public static void main(String[] args){
        int[] arr = {1, 3, 4, 6, 10};
        int t= 8;
        int left = 0;
        int right = arr.length - 1;
        boolean found = false;
        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum == t){
                found = true;
                break;
            }
            else if(sum < t){
                left++;
            }
            else{
                right--;
            }
        }
        System.out.println(found);
    }
}
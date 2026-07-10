import java.util.*;
public class Question2 {
    public static boolean isTriplet(int[] arr){
        Arrays.sort(arr);
        for(int k = arr.length - 1;k >= 2;k--){
            int left = 0, right = k - 1;
            while(left < right){
                if(arr[left]+ arr[right] == arr[k]){
                    return true;
                }else if(arr[left] + arr[right] > arr[k]){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return false;
    }
    public static void main(String[] args){
        int[] arr = {4,1,3,2,5};
        System.out.println(isTriplet(arr));
    }
}

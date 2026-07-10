import java.util.Arrays;

class Q2 {
    public boolean hasTripletSum(int[] arr) {
        Arrays.sort(arr);
        
        for (int i = arr.length - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;
            
            while (left < right) {
                int currentSum = arr[left] + arr[right];
                
                if (currentSum == arr[i]) {
                    return true; 
                } else if (currentSum < arr[i]) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return false;
    }
}
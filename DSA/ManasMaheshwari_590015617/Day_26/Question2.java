import java.util.Arrays;

class Question2 {
    public static void main(String[] args) {
        int[] arr = {4, 1, 3, 2, 5}; // Sample test case
        
        Arrays.sort(arr);
        boolean found = false;
        
        for (int i = arr.length - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;
            
            while (left < right) {
                int sum = arr[left] + arr[right];
                
                if (sum == arr[i]) {
                    found = true;
                    break;
                } else if (sum < arr[i]) {
                    left++;
                } else {
                    right--;
                }
            }
            
            if (found) {
                break;
            }
        }
        
        System.out.println(found);
    }
}

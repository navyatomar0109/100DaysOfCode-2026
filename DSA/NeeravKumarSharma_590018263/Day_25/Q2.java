class Q2 {
    public boolean hasPairWithSum(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left < right) {
            int currentSum = arr[left] + arr[right];
            
            if (currentSum == target) {
                return true; 
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return false;
    }
}
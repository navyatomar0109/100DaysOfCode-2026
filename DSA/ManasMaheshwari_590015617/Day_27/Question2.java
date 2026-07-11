class Question2 {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5}; // Sample test case
        int l = 2;
        int r = 5;
        
        System.out.println(count(arr, r) - count(arr, l - 1));
    }
    
    private static int count(int[] arr, int bound) {
        int res = 0;
        int current = 0;
        
        for (int num : arr) {
            if (num <= bound) {
                current++;
                res += current;
            } else {
                current = 0;
            }
        }
        
        return res;
    }
}

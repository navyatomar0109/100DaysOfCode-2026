class Solution {
    public boolean isHappy(int n) {
        
        HashSet<Integer> set = new HashSet<>();

        int num = n;

        while( num != 1 ){
            int sum = 0;
            while( num > 0 ){
                int digit = num % 10;
                int square = digit * digit;
                sum += square;
                num = num / 10;
                
            }
            num = sum;

            if(set.contains(num)){
                return false;
            }
            set.add(num);
            
        }
        return true;
    }
}
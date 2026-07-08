class Solution {
    public boolean isHappy(int n) {

        for (int i = 0; i < 1000; i++) {
            if (n == 1) {
                return true;
            }

            int sum = 0;

            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;
        }

        return false;
    }
}
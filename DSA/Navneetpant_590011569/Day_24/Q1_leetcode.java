class Solution {
    public boolean isHappy(int n) {

        int slow = n;
        int fast = n;

        do {
            int sum = 0;
            while (slow > 0) {
                int digit = slow % 10;
                sum += digit * digit;
                slow  = slow / 10;
            }
            slow = sum;

            for (int i = 0; i < 2; i++) {
                sum = 0;
                while (fast > 0) {
                    int digit = fast % 10;
                    sum += digit * digit;
                    fast /= 10;
                }
                fast = sum;
            }

        } while (slow != fast);

        return slow == 1;
    }
}
class Solution {
    public boolean isHappy(int n) {
        int slow=n;
        int fast=n;
        do 
        {
            slow = getSum(slow);
            fast = getSum(getSum(fast));
        } while (slow != fast);

        return slow == 1;
    }

    private int getSum(int n) 
    {
        int sum = 0;
        while (n > 0) 
        {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
}

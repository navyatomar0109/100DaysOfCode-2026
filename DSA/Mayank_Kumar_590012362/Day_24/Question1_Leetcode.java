public class Question1_Leetcode {
    
}
class Solution {
    int f(int n) {
        int s = 0;
        while (n > 0) { s += (n % 10) * (n % 10); n /= 10; }
        return s;
    }
    public boolean isHappy(int n) {
        int s = n, f = n;
        do { s = f(s); f = f(f(f)); } while (s != f);
        return s == 1;
    }
}
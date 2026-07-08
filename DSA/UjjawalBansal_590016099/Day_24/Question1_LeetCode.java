public class Question1_LeetCode {
    public static int digit_square_sum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n%10;
            sum += (d*d);
            n /= 10;
        }
        return sum;
    }

    public boolean isHappy(int n) {
        int a = n;
        int b = digit_square_sum(n);

        while (b != 1 && a != b) {
            a = digit_square_sum(a);
            b = digit_square_sum(digit_square_sum(b));
        }
        return b == 1;
    }
}

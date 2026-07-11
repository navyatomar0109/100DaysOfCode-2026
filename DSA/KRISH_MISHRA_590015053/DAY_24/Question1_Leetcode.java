import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        System.out.println(isHappy(n));

        sc.close();
    }

    public static boolean isHappy(int n) {
        int slow = getNextNumber(n);
        int fast = getNextNumber(getNextNumber(n));

        while (slow != fast) {
            if (fast == 1) return true;
            slow = getNextNumber(slow);
            fast = getNextNumber(getNextNumber(fast));
        }

        return slow == 1;
    }

    private static int getNextNumber(int n) {
        int output = 0;

        while (n > 0) {
            int digit = n % 10;
            output += digit * digit;
            n = n / 10;
        }

        return output;
    }
}

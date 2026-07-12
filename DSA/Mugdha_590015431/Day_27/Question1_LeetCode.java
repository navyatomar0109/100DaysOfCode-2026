package DSA.Mugdha_590015431.Day_27;
import java.util.*;

public class Question1_LeetCode {

    public static int compress(char[] chars) {
        int write = 0;
        int read = 0;

        while (read < chars.length) {
            char current = chars[read];
            int count = 0;

            while (read < chars.length && chars[read] == current) {
                read++;
                count++;
            }

            chars[write++] = current;

            if (count > 1) {
                char[] digits = String.valueOf(count).toCharArray();
                for (char c : digits) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        char[] chars = new char[n];

        for (int i = 0; i < n; i++) {
            chars[i] = sc.next().charAt(0);
        }

        int length = compress(chars);

        System.out.println(length);

        sc.close();
    }
}
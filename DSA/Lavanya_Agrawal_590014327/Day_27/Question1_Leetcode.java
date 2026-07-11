import java.util.*;

public class Question1_Leetcode {

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

        String input = sc.nextLine();

        input = input.substring(input.indexOf('[') + 1, input.lastIndexOf(']'));
        input = input.replace("\"", "").replace(",", " ").trim();

        if (input.isEmpty()) {
            System.out.println(0);
            sc.close();
            return;
        }

        String[] parts = input.split("\\s+");
        char[] chars = new char[parts.length];

        for (int i = 0; i < parts.length; i++) {
            chars[i] = parts[i].charAt(0);
        }

        System.out.println(compress(chars));

        sc.close();
    }
}
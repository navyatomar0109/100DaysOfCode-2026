import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        System.out.println(solve(s));

        sc.close();
    }

    public static String solve(String s) {
        s = s.toLowerCase();
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if ("aeiouy".indexOf(c) == -1) {
                result.append('.').append(c);
            }
        }

        return result.toString();
    }
}

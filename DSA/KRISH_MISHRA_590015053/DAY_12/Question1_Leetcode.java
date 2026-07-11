import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] widths = new int[26];
        for (int i = 0; i < 26; i++) {
            widths[i] = sc.nextInt();
        }

        String s = sc.next();

        int[] result = numberOfLines(widths, s);

        System.out.println(result[0] + " " + result[1]);

        sc.close();
    }

    public static int[] numberOfLines(int[] widths, String s) {
        int lines = 1, width = 0;

        for (int i = 0; i < s.length(); i++) {
            int w = widths[s.charAt(i) - 'a'];
            width += w;

            if (width > 100) {
                lines++;
                width = w;
            }
        }

        return new int[]{lines, width};
    }
}

package DSA.Mugdha_590015431.Day_23;
import java.util.*;

public class Question1_LeetCode {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] g = new int[n];

        for (int i = 0; i < n; i++) {
            g[i] = sc.nextInt();
        }

        int m = sc.nextInt();
        int[] s = new int[m];

        for (int i = 0; i < m; i++) {
            s[i] = sc.nextInt();
        }

        Arrays.sort(g);
        Arrays.sort(s);

        int child = 0;
        int cookie = 0;

        while (child < g.length && cookie < s.length) {
            if (s[cookie] >= g[child]) {
                child++;
            }
            cookie++;
        }

        System.out.println(child);

        sc.close();
    }
}
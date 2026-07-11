import java.util.*;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int l = sc.nextInt();
        int r = sc.nextInt();

        int count = 0;

        for (int i = 0; i < n; i++) {
            int max = arr[i];
            for (int j = i; j < n; j++) {
                if (arr[j] > max) {
                    max = arr[j];
                }
                if (max >= l && max <= r) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }
}
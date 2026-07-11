import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println(hasTriplet(arr));

        sc.close();
    }

    public static boolean hasTriplet(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            while (i < j) {
                int sum = arr[i] + arr[j];

                if (sum == arr[k]) {
                    return true;
                } else if (sum < arr[k]) {
                    i++;
                } else {
                    j--;
                }
            }
        }

        return false;
    }
}

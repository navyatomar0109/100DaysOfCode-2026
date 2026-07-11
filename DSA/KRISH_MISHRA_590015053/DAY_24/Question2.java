import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int[] result = sortedSquares(nums);

        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println();

        sc.close();
    }

    public static int[] sortedSquares(int[] nums) {
        int[] res = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            res[i] = nums[i] * nums[i];
        }

        Arrays.sort(res);

        return res;
    }
}

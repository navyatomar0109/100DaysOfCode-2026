import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int[] result = scores(nums);

        System.out.println(result[0] + " " + result[1]);

        sc.close();
    }

    public static int[] scores(int[] nums) {
        int i = 0, j = nums.length - 1;
        int p1 = 0, p2 = 0;
        boolean turn = true;

        while (i <= j) {
            int pick;
            if (nums[i] > nums[j]) {
                pick = nums[i++];
            } else {
                pick = nums[j--];
            }

            if (turn) {
                p1 += pick;
            } else {
                p2 += pick;
            }

            turn = !turn;
        }

        return new int[]{p1, p2};
    }
}

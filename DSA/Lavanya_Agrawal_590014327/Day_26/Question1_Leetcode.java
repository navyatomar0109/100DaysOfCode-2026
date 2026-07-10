import java.util.*;

public class Question1_Leetcode {

    public static void sortColors(int[] nums) {
        int low = 0;
        int mid = 0;
        int high = nums.length - 1;

        while (mid <= high) {
            switch (nums[mid]) {
                case 0 -> {
                    int temp = nums[low];
                    nums[low] = nums[mid];
                    nums[mid] = temp;
                    low++;
                    mid++;
                }
                case 1 -> mid++;
                default -> {
                    int temp = nums[mid];
                    nums[mid] = nums[high];
                    nums[high] = temp;
                    high--;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        sortColors(nums);

        System.out.print("[");
        for (int i = 0; i < n; i++) {
            System.out.print(nums[i]);
            if (i != n - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");

        sc.close();
    }
}
public class PartB {
    public static int sum(int[] nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        return total;
    }

    public static void main(String[] args) {
        int[] input = {3, 8, 2, 9, 1};
        System.out.println(sum(input));
    }
}

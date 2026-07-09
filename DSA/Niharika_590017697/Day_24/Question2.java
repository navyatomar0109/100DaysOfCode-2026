import java.util.*;
class Question2 
{
    public static int[] sortedSquares(int[] nums) 
    {
        int n = nums.length;
        int[] ans = new int[n];
        int left = 0;
        int right = n - 1;
        int idx = n - 1;

        while (left <= right) 
        {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                ans[idx] = leftSquare;
                left++;
            } else {
                ans[idx] = rightSquare;
                right--;
            }
            idx--;
        }
        return ans;
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size: ");
        int n = sc.nextInt();

        int[] nums = new int[n];
        System.out.println("Enter array elements: ");
        for (int i = 0; i < n; i++) 
        {
            nums[i] = sc.nextInt();
        }

        int[] result = sortedSquares(nums);
        System.out.print("[");
        for (int i = 0; i < result.length; i++) 
        {
            System.out.print(result[i]);
            if (i != result.length - 1) 
            {
                System.out.print(", ");
            }
        }
        System.out.println("]");

        sc.close();
    }
}

class Part_B {

public static int largest(int[] nums)
{
int max = nums[0];
for (int i = 1; i < nums.length; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max;
}
public static void main(String[] args)
{
    int[] nums = {3, 7, 9, 2, 5};
    int result = largest(nums);
    System.out.println("Largest Element: " + result);
    }
}
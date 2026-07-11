
import java.util.Arrays;
class TSC{
    public static void main(String[] args) {
        int[] arr = {4, 1, 3, 2, 7};
        Arrays.sort(arr);
        boolean found = false;
        for (int k = arr.length - 1; k >= 2; k--) {
            int left = 0;
            int right = k - 1;
            while (left < right) {
                int sum = arr[left] + arr[right];
                if (sum == arr[k]) {
                    found = true;
                    break;
                }
                else if (sum < arr[k]) {
                    left++;
                }
                else {
                    right--;
                }
            }
            if (found)
                break;
        }
        System.out.println(found);
    }
}
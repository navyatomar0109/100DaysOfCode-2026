import java.util.Arrays;

public class Question2 {

    public static boolean hasTriplet(int[] arr){

        Arrays.sort(arr);

        for(int i=arr.length-1;i>=2;i--){

            int left=0;
            int right=i-1;

            while(left<right){

                int sum=arr[left]+arr[right];

                if(sum==arr[i])
                    return true;

                if(sum<arr[i])
                    left++;
                else
                    right--;
            }
        }

        return false;
    }

    public static void main(String[] args){

        int[] arr={4,1,3,2,5};

        System.out.println(hasTriplet(arr));
    }
}
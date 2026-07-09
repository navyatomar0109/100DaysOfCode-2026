public class Question2 {

    public static boolean hasPair(int[] arr,int target){

        int left=0;
        int right=arr.length-1;

        while(left<right){

            int sum=arr[left]+arr[right];

            if(sum==target)
                return true;

            if(sum<target)
                left++;
            else
                right--;
        }

        return false;
    }

    public static void main(String[] args){

        int[] arr={1,2,4,6,10};
        int target=8;

        System.out.println(hasPair(arr,target));
    }
}
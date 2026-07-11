public class Question2 {

    public static int count(int[] arr,int bound){

        int ans=0;
        int len=0;

        for(int num:arr){

            if(num<=bound)
                len++;
            else
                len=0;

            ans+=len;
        }

        return ans;
    }

    public static int numSubarrayBoundedMax(int[] arr,int l,int r){

        return count(arr,r)-count(arr,l-1);
    }

    public static void main(String[] args){

        int[] arr={1,2,3,4,5};
        int l=2;
        int r=5;

        System.out.println(numSubarrayBoundedMax(arr,l,r));
    }
}
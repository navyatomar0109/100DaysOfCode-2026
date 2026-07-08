public class Question2 {

    public static int[] sortedSquares(int[] nums){

        int n=nums.length;
        int[] ans=new int[n];

        int left=0;
        int right=n-1;
        int index=n-1;

        while(left<=right){

            int leftSquare=nums[left]*nums[left];
            int rightSquare=nums[right]*nums[right];

            if(leftSquare>rightSquare){
                ans[index]=leftSquare;
                left++;
            }
            else{
                ans[index]=rightSquare;
                right--;
            }

            index--;
        }

        return ans;
    }

    public static void main(String[] args){

        int[] nums={-4,-1,0,3,10};

        int[] ans=sortedSquares(nums);

        System.out.print("[");

        for(int i=0;i<ans.length;i++){

            System.out.print(ans[i]);

            if(i!=ans.length-1)
                System.out.print(",");
        }

        System.out.println("]");
    }
}
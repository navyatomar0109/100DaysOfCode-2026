class Question2{
    public static boolean isPair(int[] arr, int target){
        int i = 0, j = arr.length - 1;
        while(i < j){
            if(arr[i] + arr[j] == target){
                return true;
            }else if(arr[i] + arr[j] > target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
    public static void main(String[] args){
        int[] arr = {1,2,4,6,10};
        int target = 8;
        System.out.println(isPair(arr,target));
    }
}
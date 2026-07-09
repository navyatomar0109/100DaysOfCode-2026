public class Pair_withSum {

    public static boolean PairExistsCheck( int[] arr , int sum ){

        int left = 0 , right = arr.length - 1;

        while( left < right ){

            if( arr[left] + arr[right] == sum ){
                return true;
            }
            else if( arr[left] + arr[right] < sum ){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }

    public static void main(String[] args){
        
        int[] arr = {1, 2, 3, 4, 6};
        int target = 10;

        boolean result = PairExistsCheck(arr, target);
        System.out.println(result);
    }
    
}

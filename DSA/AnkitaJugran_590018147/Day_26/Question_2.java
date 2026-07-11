import java.util.Arrays;

public class TripletSumCheck {
    
    public static boolean TripletCheck( int[] arr){


        for( int third = arr.length - 1; third >= 0 ; third-- ){

            int first = 0 , second = arr.length - 2;

            while( first < second ){

                if( arr[first] + arr[second] == arr[third] ){
                    return true;
                }
                else if( arr[first] + arr[second] < arr[third] ){
                    first++;
                }
                else{
                    second--;
                }
            }
        }
        return false;
    }

    public static void main(String[] args){
        
        int[] arr = {4 , 1 , 3 , 2 , 5};

        Arrays.sort(arr);

        boolean result = TripletCheck(arr);
        System.out.println(result);
    }
}

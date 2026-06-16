package Day_2;

public class Question_2 {
    public int Largest(int[]arr){
        int largest=arr[0];
        for (int num:arr){
            if(num> largest){
                largest=num;
            }
        }
        return largest;
    }
}

import java.util.Scanner;

public class Question2 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter size:");
        int size=sc.nextInt();
        int[] arr=new int[size];
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();

        }
          int temp = 0;
        boolean swapped;
        
        do {
            swapped = false;
            for(int i = 0; i < arr.length - 1; i++){
                if(arr[i] > arr[i+1]){
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    swapped = true;
                }
            }
        } while(swapped);
        

        for(int index=arr.length-1;index>=2;index--){
        int left=0;
        
        int right=index-1;
        while (left < right) {
            if (arr[left] + arr[right] < arr[index]) {
    left++;
} else if (arr[left] + arr[right] > arr[index]) {
    right--;
} else {
    System.out.println("true");
    return;
    
}

        }
        System.out.println("false");
        
    }
    
}
}

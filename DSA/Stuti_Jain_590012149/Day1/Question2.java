import java.util.Scanner;

public class Question2 {
    public static void main(String[] args){
        int sum = 0;
        int n = 0;

        Scanner s = new Scanner(System.in);

        System.out.println("Enter the size of the array: ");
        n = s.nextInt();

        int arr[] = new int[n];
        System.out.println("Enter the elements of the array: ");


        for(int i=0; i<n; i++) {
            arr[i] = s.nextInt();
            sum += arr[i];

        }

        System.out.println("The sum of the elements of the array is: " + sum);

        s.close();

    }

}

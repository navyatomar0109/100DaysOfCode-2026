package DSA.Mugdha_590015431.Day_1;
import java.util.*;
public class Question2 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter length of array: ");
        int n=sc.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter elements of array:");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Sum of elements in array is: "+sum(arr));
        sc.close();
    }
    public static int sum(int arr[]){
        int sum=0;
        for(int num:arr){
            sum+=num;
        }
        return sum;
    }
}

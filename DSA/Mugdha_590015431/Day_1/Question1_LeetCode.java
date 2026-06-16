package DSA.Mugdha_590015431.Day_1;
import java.util.*;
public class Question1_LeetCode {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter length of array:");
        int n=sc.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter elements of array:");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Missing number is: "+missingNum(arr));
        sc.close();
    }
    public static int missingNum(int arr[]){
        int n=arr.length;
        int sum=(n*(n+1)/2);
        int actualSum=0;
        for(int num:arr){
            actualSum+=num;
        }
        return sum-actualSum;
    }
}
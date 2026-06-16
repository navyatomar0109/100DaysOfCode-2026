package DSA.Mugdha_590015431.Day_2;
import java.util.*;
public class Question1_Leetcode {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(); //length of arrray
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int val=sc.nextInt();
        int k=remove(arr,val);
        for(int i=0;i<k;i++){
            System.out.print(arr[i]+" ");
        }
        sc.close();
    }
    public static int remove(int arr[],int val){
        int k=0;
        for (int num:arr){
            if(num!=val){
                arr[k]=num;
                k++;
            }
        }
        return k;
    }
}

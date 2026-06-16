package 100DaysOfCode-2026.DSA.Kaashya_Gupta_590013119.Day2;
import java.util.*;
public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        int max = 0;
        for (int i=0; i<n; i++){
            if (arr[i]>max){
                max = arr[i];
            }
        }
        System.out.println(max);
        sc.close();        
    }
}

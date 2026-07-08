package DSA.TanmaySharma_590011578.Day_23;

import java.util.Scanner;
public class Question2{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String A=in.nextLine();
        String B= in.nextLine();
        System.out.println(CheckingBackspaceEquality(A,B));

    }
    public static boolean CheckingBackspaceEquality(String A,String B){
        int i= A.length()-1;
        int j=B.length()-1;
        while (i>=0||j>=0){
            int skipA=0;
            while(i>=0){
                if(A.charAt(i)=='#'){
                    skipA++;
                    i--;

                }else if (skipA>0){
                    skipA--;
                    i--;
                }else {
                    break;
                }
            }
            int skipB=0;
            while(j>=0){
                if(B.charAt(j)=='#'){
                    skipB++;
                    j--;
                }else if(skipB>0){
                    skipB--;
                    j--;

                }else{
                    break;
                }
            }
            if(i>=0 && j>=0){
                if(A.charAt(i)!=B.charAt(j)){
                    return false;
                }
            }else if(i>=0||j>=0){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
}
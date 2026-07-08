package Day_23;

import java.util.*;
public class d23question1_technical {
    
    public static String HashBack(String a){
        String Hrm= "";
        int j = 0;
        for(int i=0;i<a.length();i++){
            if(a.charAt(i)!='#'){Hrm=Hrm+a.charAt(i);j++;}
            else{
                Hrm=Hrm.substring(0,--j);
            }}
        return Hrm;
    } 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first String: ");
        String n = sc.nextLine();     
        System.out.print("Enter second String: ");
        String s = sc.nextLine(); 
        System.out.print((HashBack(n).equals(HashBack(s))));              
        sc.close();
    }
}

import java.util.*;
public class Main {
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first string: ");
        String s = sc.nextLine();
        System.out.print("Enter second string: ");
        String t = sc.nextLine();
        String ans1 = "";
        String ans2 = "";
        for (int i = 0; i < s.length(); i++) 
        {
            char ch = s.charAt(i);
            if (ch == '#') 
            {
                if (ans1.length() > 0) 
                {
                    ans1 = ans1.substring(0, ans1.length() - 1);
                }
            } else 
            {
                ans1 = ans1 + ch;
            }
        }
        for (int i = 0; i < t.length(); i++) {

            char ch = t.charAt(i);

            if (ch == '#') 
            {
                if (ans2.length() > 0) 
                {
                    ans2 = ans2.substring(0, ans2.length() - 1);
                }
            } else 
            {
                ans2 = ans2 + ch;
            }
        }
        if (ans1.equals(ans2))
        {
            System.out.println("true");
        } else 
        {
            System.out.println("false");
        }
    }
}
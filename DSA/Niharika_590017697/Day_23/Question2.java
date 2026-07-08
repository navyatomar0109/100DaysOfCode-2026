import java.util.Scanner;
class Question2 
{
    public static boolean backspaceCompare(String s, String t) 
    {
        int i=s.length()-1, j=t.length()-1;
        while (i>=0 || j>=0) 
        {
            int skip1 = 0; //skip1 is for backspace count of string s
            while (i >= 0) 
            {
                if (s.charAt(i) == '#') 
                {
                    skip1++;
                    i--;
                } 
                else if (skip1 > 0) 
                {
                    skip1--;
                    i--;
                } 
                else
                    break;
            }

            int skip2 = 0; // skip2 is for backspace count of string t
            while (j >= 0) 
            {
                if (t.charAt(j) == '#') 
                {
                    skip2++;
                    j--;
                } 
                else if (skip2 > 0) 
                {
                    skip2--;
                    j--;
                } 
                else
                    break;
            }

            if (i >= 0 && j >= 0) 
            {
                if (s.charAt(i) != t.charAt(j)) 
                {
                    return false;
                }
            } 
            else if (i >= 0 || j >= 0) 
            {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter string s: ");
        String s = sc.next();
        System.out.println("Enter string t: ");
        String t = sc.next();
        System.out.println("Output: " + backspaceCompare(s, t));

        sc.close();
    }
}

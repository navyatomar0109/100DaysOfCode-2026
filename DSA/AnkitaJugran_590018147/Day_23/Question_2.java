public class Backspace_equality {

    public static void main(String[] args) {
        String str1 = "ab#c";
        String str2 = "ad#c";

        System.out.println(backspaceCompare(str1, str2));
    }

    //method to compare two strings with backspace characters
    public static boolean backspaceCompare(String s, String t) {

        //pointers will start from the end of both strings
        int ptr1 = s.length() - 1;
        int ptr2 = t.length() - 1;


        while (ptr1 >= 0 || ptr2 >= 0) {
            ptr1 = findNextValidChar(s, ptr1);
            ptr2 = findNextValidChar(t, ptr2);


            if (ptr1 < 0 && ptr2 < 0) {
                return true;
            }

            if (ptr1 < 0 || ptr2 < 0) {
                return false;
            }

            if (s.charAt(ptr1) != t.charAt(ptr2)) {
                return false;
            }
            ptr1--;
            ptr2--;
        }

        return true;
    }

    // Moves ptr backward, skipping any backspaced characters
    // until it lands on a valid character or goes below 0.
    private static int findNextValidChar(String s, int ptr) {
        int skip = 0;

        while (ptr >= 0) {
            if (s.charAt(ptr) == '#') {
                skip++;
                ptr--;
            } else if (skip > 0) {
                skip--;
                ptr--;
            } else {
                break; // landed on a valid character
            }
        }

        return ptr;
    }
}
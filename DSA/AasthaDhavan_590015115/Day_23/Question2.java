import java.util.Stack;
public class Question2 {
    static String build(String str) {
        Stack<Character> st = new Stack<>();
        for (char ch : str.toCharArray()) {
            if (ch == '#') {
                if (!st.isEmpty())
                    st.pop();
            } else {
                st.push(ch);
            }
        }
        StringBuilder ans = new StringBuilder();
        for (char ch : st)
            ans.append(ch);

        return ans.toString();
    }
    public static boolean backspaceEqual(String s, String t) {
        return build(s).equals(build(t));
    }

    public static void main(String[] args) {
        String s = "ab#c";
        String t = "ad#c";

        System.out.println(backspaceEqual(s, t));
    }
}
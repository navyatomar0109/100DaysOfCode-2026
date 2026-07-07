class Solution {
    private String process(String str) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch != '#') {
                sb.append(ch);
            } else {
                if (sb.length() > 0) {
                    sb.deleteCharAt(sb.length() - 1);
                }
            }
        }
        return sb.toString();
    }
    public boolean backspaceCompare(String s, String t) {
        return process(s).equals(process(t));

    }
}
class Solution {
    public boolean backspaceCompare(String s, String t) {
        return build(s).equals(build(t));
    }

    String build(String s) {
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (c != '#')
                sb.append(c);
            else if (sb.length() > 0)
                sb.deleteCharAt(sb.length() - 1);
        }

        return sb.toString();
    }
}
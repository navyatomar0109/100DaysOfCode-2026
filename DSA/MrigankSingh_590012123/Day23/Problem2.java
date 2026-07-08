public class Problem2 {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length() - 1;
        int j = t.length() - 1;

        while (i >= 0 || j >= 0) {
            i = getNextValidIndex(s, i);
            j = getNextValidIndex(t, j);

            if (i < 0 || j < 0) {
                return i == j;
            }

            if (s.charAt(i) != t.charAt(j)) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }

    private int getNextValidIndex(String str, int index) {
        int skip = 0;

        while (index >= 0) {
            if (str.charAt(index) == '#') {
                skip++;
                index--;
            } else if (skip > 0) {
                skip--;
                index--;
            } else {
                break;
            }
        }

        return index;
    }
}
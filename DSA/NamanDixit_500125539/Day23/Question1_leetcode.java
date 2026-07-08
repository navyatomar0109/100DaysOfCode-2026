
import java.util.Arrays;

class Question1_leetcode {

    public int findContentChildren(int[] g, int[] s) {

        // Sort greed factors
        Arrays.sort(g);

        // Sort cookie sizes
        Arrays.sort(s);

        // Pointer for children
        int i = 0;

        // Pointer for cookies
        int j = 0;

        // Count of satisfied children
        int count = 0;

        // Continue until all children or all cookies are checked
        while (i < g.length && j < s.length) {

            // If current cookie can satisfy current child
            if (s[j] >= g[i]) {

                // Child gets the cookie
                count++;

                // Move to next child
                i++;

                // Move to next cookie
                j++;

            } else {

                // Cookie is too small
                // Try the next bigger cookie
                j++;
            }
        }

        // Return maximum satisfied children
        return count;
    }
}

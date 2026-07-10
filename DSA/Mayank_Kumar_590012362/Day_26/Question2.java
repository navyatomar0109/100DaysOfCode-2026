import java.util.Arrays;
public class Question2 {
    public boolean hasTriplet(int[] a) {
        Arrays.sort(a);
        for (int i = a.length - 1; i > 1; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                int s = a[l] + a[r];
                if (s == a[i]) return true;
                if (s < a[i]) l++;
                else r--;
            }
        } return false;
    }
}
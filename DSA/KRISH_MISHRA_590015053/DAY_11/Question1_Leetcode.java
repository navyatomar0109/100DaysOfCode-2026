import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();
        String t = sc.nextLine();

        System.out.println(isIsomorphic(s, t));

        sc.close();
    }

    public static boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> mapST = new HashMap<>();
        HashMap<Character, Character> mapTS = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char sc = s.charAt(i);
            char tc = t.charAt(i);

            if (mapST.containsKey(sc)) {
                if (mapST.get(sc) != tc) {
                    return false;
                }
            } else if (mapTS.containsKey(tc)) {
                return false;
            }

            mapST.put(sc, tc);
            mapTS.put(tc, sc);
        }

        return true;
    }
}

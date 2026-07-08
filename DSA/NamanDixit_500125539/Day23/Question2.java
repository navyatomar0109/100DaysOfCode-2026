import java.util.Scanner;

public class Question2 {

    // Function to process the string after applying backspaces
    public static String processString(String str) {

        // StringBuilder is used to build the final string
        StringBuilder result = new StringBuilder();

        // Traverse every character of the string
        for (int i = 0; i < str.length(); i++) {

            char ch = str.charAt(i);

            // If character is '#', remove the last character (if any)
            if (ch == '#') {

                // Check if there is a character to remove
                if (result.length() > 0) {
                    result.deleteCharAt(result.length() - 1);
                }

            } else {

                // Otherwise, add the character
                result.append(ch);
            }
        }

        // Return the processed string
        return result.toString();
    }

    public static void main(String[] args) {

        // Create Scanner object
        Scanner sc = new Scanner(System.in);

        // Input first string
        System.out.print("Enter first string: ");
        String s = sc.nextLine();

        // Input second string
        System.out.print("Enter second string: ");
        String t = sc.nextLine();

        // Process both strings
        String first = processString(s);
        String second = processString(t);

        // Compare the processed strings
        if (first.equals(second)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }

        // Close scanner
        sc.close();
    }
}
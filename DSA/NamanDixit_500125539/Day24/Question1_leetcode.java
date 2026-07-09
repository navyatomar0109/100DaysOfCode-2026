import java.util.HashSet;

class Question1_leetcode {

    public boolean isHappy(int n) {

        // HashSet is used to store numbers we have already seen
        HashSet<Integer> seen = new HashSet<>();

        // Continue until n becomes 1
        while (n != 1) {

            // If we have already seen this number,
            // a loop is formed
            if (seen.contains(n)) {
                return false;
            }

            // Store the current number
            seen.add(n);

            // Variable to store the sum of squares of digits
            int sum = 0;

            // Find the sum of squares of each digit
            while (n > 0) {

                // Get the last digit
                int digit = n % 10;

                // Add square of the digit
                sum = sum + (digit * digit);

                // Remove the last digit
                n = n / 10;
            }

            // Update n with the new sum
            n = sum;
        }

        // If n becomes 1, it is a Happy Number
        return true;
    }
}
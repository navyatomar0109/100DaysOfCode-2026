//Need to check if the number eventually becomes 1

import java.util.HashSet;

class Solution {

    public boolean isHappy(int n) {

        HashSet<Integer> seen = new HashSet<>();

        // if a number repeats, we're stuck in a loop
        while (n != 1 && !seen.contains(n)) {

            seen.add(n);

            int sum = 0;

            // keep adding squares of digits
            while (n > 0) {

                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;
        }

        return n == 1;
    }
}
#include <stdbool.h>

int squareSum(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;

    while (1) {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));

        if (slow == fast) {
            break;
        }
    }

    return slow == 1;
}

#include <stdio.h>

int squareSum(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

int isHappy(int n) {

    int slow = n;
    int fast = n;

    do {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));
    } while (slow != fast);

    return slow == 1;
}

int main() {

    int n = 19;

    if (isHappy(n))
        printf("Happy Number\n");
    else
        printf("Not a Happy Number\n");

    return 0;
}
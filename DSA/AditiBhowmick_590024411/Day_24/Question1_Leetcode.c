#include <stdio.h>
#include <stdbool.h>

// Function to calculate the sum of squares of digits
int sumOfSquares(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

// Function to check if the number is happy
bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
        slow = sumOfSquares(slow);
        fast = sumOfSquares(sumOfSquares(fast));
    } while (slow != fast);

    return slow == 1;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isHappy(n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
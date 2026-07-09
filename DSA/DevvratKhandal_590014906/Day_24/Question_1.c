#include <stdio.h>

int getSum(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

int isHappy(int n) {
    int slow = n, fast = n;

    do {
        slow = getSum(slow);
        fast = getSum(getSum(fast));
    } while (slow != fast);

    return slow == 1;
}

int main() {
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    if (isHappy(n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
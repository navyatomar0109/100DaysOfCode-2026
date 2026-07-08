// Leetcode Problem 202
// Happy Number

int sumSquare(int n){
    int sum = 0;
    while (n > 0){
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;
    do{
        slow = sumSquare(slow);
        fast = sumSquare(sumSquare(fast));
    }
    while (slow != fast);

    if (slow == 1)
        return true;
    else
        return false;
}
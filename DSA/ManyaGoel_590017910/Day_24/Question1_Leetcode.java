public class Question1_Leetcode{
    public boolean isHappy(int n) {
        int slow=SumOfSquares(n); // Initialize a slow pointer to the sum of squares of the digits of n
        int fast=SumOfSquares(SumOfSquares(n)); // Initialize a fast pointer to the sum of squares  of the digits of the sum of squares of n

        // Use the Floyd's Cycle Detection algorithm to check for cycles in the sequence of sums of squares by moving slow by one step and fast by two steps
        // If they meet, either we've reached 1 or entered a cycle
        while(slow!=fast){
            slow=SumOfSquares(slow);
            fast=SumOfSquares(SumOfSquares(fast));
        }

        return slow==1; // Return true if the slow pointer reaches 1, indicating that n is a happy number; otherwise, return false
    }
    
    // Function to calculate the sum of squares of the digits of a number
    private int SumOfSquares(int num){
        int sum=0;
        while( num > 0){
            int remainder=num % 10;
            sum+= remainder*remainder;
            num/=10;
        }
        return sum;
    }
}
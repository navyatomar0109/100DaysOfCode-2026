// to check whether the given number is happy number or not

class Solution {
public:
    bool isHappy(int n) {
                if(n==1 || n==7) return true;
//  If the number is 1 or 7, return true (happy number).
        else if(n<10) return false;
        else{
            int sum=0;
            while(n>0){
                int temp=n%10;
                sum+= temp*temp;
                n=n/10;
            }
            return isHappy(sum);
        }
    }
};
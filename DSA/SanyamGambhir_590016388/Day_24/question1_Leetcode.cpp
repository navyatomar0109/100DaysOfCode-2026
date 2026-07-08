class Solution {
public:

    int calsum(int m){
        int sum = 0;
        while(m != 0){
            int digit = m % 10;
            m = m/10;
            sum = sum + (digit*digit);
        }
        return sum;
        
    }
    bool isHappy(int n) {
        set<int>mp;
        while(n != 1){
            if(mp.find(n) != mp.end()){
                return false;
            }
            mp.insert(n);
            n = calsum(n);
        }
        return true;
    }
};
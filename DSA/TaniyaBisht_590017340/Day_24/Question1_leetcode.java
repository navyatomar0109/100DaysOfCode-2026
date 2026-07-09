
class Solution{
    public boolean isHappy(int n){
        HashSet<Integer> hs = new HashSet<>();
        while(!hs.contains(n)){
            hs.add(n);
            int sqrSum = 0;
            while(n != 0){
                int rem = n%10;
                sqrSum += rem * rem;
                n = n/10;
            }
            if(sqrSum == 1){
                return true;
            }
            n = sqrSum;
        }
        return false;
    }
}
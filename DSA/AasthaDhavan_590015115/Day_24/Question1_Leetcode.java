class Solution {
    public boolean isHappy(int n) {
        Set<Integer> used=new HashSet<>();
        while(true){
            int sum=0;
            while(n!=0){
               int digit=n%10;
               sum+=digit*digit;
               n/=10;
            }
            
            if(sum==1) return true;
           
            if(used.contains(sum))
                return false;
            used.add(sum);
         n=sum; 
        }
    }
}
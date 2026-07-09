class Solution {
    public boolean isHappy(int n) 
    {
        int original=n;
        while(n != 1 && n != 4)
        {
            int sum=0;
            while(n > 0)
            {
                int d=n%10;
                sum=sum+(d*d);
                n=n/10;
            }
            n=sum;
        }
        if(n==1)
        {
            return true;
        }
        else
        {
             return false;
        }
    }
}
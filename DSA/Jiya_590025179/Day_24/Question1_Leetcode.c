bool isHappy(int n) {
    if(n==1 || n==10 || n==7)
    return 1;
    else if(n<10)
    return 0;
    else {
        int rem,sum=0; 
        while(n!=0)
    {
        rem=n%10;
        sum=sum+(rem*rem);
        n=n/10;
    }
     return isHappy(sum);
    }  
}

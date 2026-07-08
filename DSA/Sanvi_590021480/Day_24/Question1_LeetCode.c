bool isHappy(int n) {
    
    while(n!=1 && n!=4) {
        int dig=0;
    for(int i=n;i!=0;i=i/10){
        dig=dig+((i%10)*(i%10));
    }
    n=dig;
    }
    return n==1;
}

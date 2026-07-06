int strStr(char* haystack, char* needle) {
    int i,j;
    int n=0;
    int m=0;
    while(haystack[n]!='\0')
        n++;
    while (needle[m]!= '\0')
        m++;
    if(m==0)
        return 0;
    for(i=0;i<=n-m; i++){
        for(j=0; j<m; j++){
            if(haystack[i+j]!= needle[j])
            break;
        }
            if(j==m)
             return i;
    }
            return -1;
}
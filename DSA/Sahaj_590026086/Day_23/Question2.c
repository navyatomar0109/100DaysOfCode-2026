#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool compare(char* s, char* t) {
    int i=strlen(s)-1;
    int j=strlen(t)-1;

    int skips=0, skipt=0;

    while(i>=0||j>= 0){
        while(i>=0){
            if(s[i]=='#') {
                skips++;
                i--;
            }
            else if(skips>0){
                skips--;
                i--;
            }
            else 
                break;
        }
        while(j>=0){
            if(t[j]=='#'){
                skipt++;
                j--;
            }
            else if(skipt>0){
                skipt--;
                j--;
            }
            else 
                break;
        }
        if(i>=0&&j>=0) {
            if(s[i]!=t[j]) return false;
        } else {
            if(i>=0||j>=0) return false;
        }
        i--; 
        j--;
    }
    return true;
}
int main(){
    char s[100], t[100];
    printf("Enter first string: ");
    scanf("%s", s);
    printf("Enter second string: ");
    scanf("%s", t);
    if(backspaceCompare(s, t))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}

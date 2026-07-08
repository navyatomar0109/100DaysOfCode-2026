#include <iostream>
#include<string>
using namespace std;

bool find(string &s, string &t){
    int i=s.size()-1;
    int j=t.size()-1;

    int skips=0;
    int skipt=0;

    while(i>=0|| j>=0){
        while(i>=0){
            if(s[i] == '#'){
                skips++;
                i--;
            }
            else if(skips>0){
                skips--;
                i--;
            }
            else{
                break;
            }
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
            else{
                break;
            }
        }

        if(i>=0 && j>=0){
            if(s[i] != t[j]){
                return false;
            }
            
        }
        else if(i>=0 || j>=0){
                return false;
            }
            i--;
            j--;

        
    }
    return true;
}
int main(){
    string s="Kh#shi";
    string t="Kh#sh#";

    if(find(s,t)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;
}
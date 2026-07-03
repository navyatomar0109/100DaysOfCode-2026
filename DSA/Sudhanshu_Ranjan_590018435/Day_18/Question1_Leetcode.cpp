#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL) return NULL;
        if (k==0) return head;
        ListNode* cur=head, *first=head;
        int n=1;
        while(cur->next){
            cur=cur->next;
            n++;
        } 
        cur->next=first;
        int pos=n+(-k)%n;
        ListNode* ans=head, *prev;
        for(int i=0; i<pos; i++){
            prev=ans;
            ans=ans->next;
        }
        prev->next=NULL;
        return ans;    
    }
};
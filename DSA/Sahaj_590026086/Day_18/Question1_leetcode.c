struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head||!head->next||k==0)
        return head;
    int n=1;
    struct ListNode*temp=head;
    while(temp->next){
        temp=temp->next;
        n++;
    }
    temp->next=head;
    k=k%n;
    int steps=n-k;
    while(steps--){
        temp=temp->next;
    }
    struct ListNode* newHead=temp->next;
    temp->next=NULL;
    return newHead;
}

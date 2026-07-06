struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode* curr=&dummy;
    while(curr->next){
        if(curr->next->val==val){
            struct ListNode* temp=curr->next;
            curr->next=curr->next->next;
            free(temp);
        }
        else{
            curr=curr->next;
        }
    }
    return dummy.next;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr=head;
    while(curr&&curr->next) {
        if(curr->val==curr->next->val){
            struct ListNode* temp=curr->next;
            curr->next=curr->next->next;
            free(temp);
        } else{
            curr=curr->next;
        }
    }
    return head;
}

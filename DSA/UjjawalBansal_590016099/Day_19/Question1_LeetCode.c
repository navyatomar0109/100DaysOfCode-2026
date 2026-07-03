struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head || !head->next) return head;
    struct ListNode* i = head;
    
    while (i->next) {
        if (i->val == i->next->val){
        struct ListNode* temp = i->next;
        i->next = temp->next;
        free(temp);
        }
        else i = i->next;
    }
    return head;
}
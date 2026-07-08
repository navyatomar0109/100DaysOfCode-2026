struct ListNode* deleteDuplicates(struct ListNode* head){
    
    struct ListNode *ptr = head;
    struct ListNode *temp;

    while(ptr != NULL && ptr->next != NULL){
        if(ptr->val == ptr->next->val){
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }else{
            ptr = ptr->next;
        }
    }

    return head;
}
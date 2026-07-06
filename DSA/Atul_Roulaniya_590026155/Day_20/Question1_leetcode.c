struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *temp;

    while(head != NULL && head->val == val){
        temp = head;
        head = head->next;
        free(temp);
    }

    struct ListNode *curr = head;

    while(curr != NULL && curr->next != NULL){
        if(curr->next->val == val){
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }else{
            curr = curr->next;
        }
    }

    return head;
}
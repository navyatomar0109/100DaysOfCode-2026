struct ListNode* removeElements(struct ListNode* head, int key){
    struct ListNode temp;
    temp.next = head;
    struct ListNode *prev = &temp;
    struct ListNode *curr = head;
    while (curr != NULL){
        if (curr->val == key) {
            prev->next = curr->next;
            struct ListNode *del = curr;
            curr = curr->next;
            free(del);
        } else{
            prev = curr;
            curr = curr->next;
        }
    }
    return temp.next;
}
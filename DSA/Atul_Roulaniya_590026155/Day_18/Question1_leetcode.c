struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }

    int len = 0;
    struct ListNode *temp = head;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }

    k = k % len;

    for(int i = 0; i < k; i++){
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;

        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        curr->next = head;
        head = curr;
    }

    return head;
}
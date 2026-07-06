struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode ptr;
    ptr.next = head;

    struct ListNode *prev = &ptr;
    struct ListNode *ptr1;
    struct ListNode *ptr2;

    while(prev->next != NULL && prev->next->next != NULL){
        ptr1 = prev->next;
        ptr2 = ptr1->next;

        ptr1->next = ptr2->next;
        ptr2->next = ptr1;
        prev->next = ptr2;

        prev = ptr1;
    }

    return ptr.next;
}
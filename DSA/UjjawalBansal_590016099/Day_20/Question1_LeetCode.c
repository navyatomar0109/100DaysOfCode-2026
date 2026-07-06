struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode a;
    a.next = head;
    struct ListNode* ans = &a;
    while (ans->next) {
        if (ans->next->val == val) {
            struct ListNode* temp = ans->next;
            ans->next = ans->next->next;
            free(temp);
        }
        else ans = ans->next;
    }
    return a.next;
}
struct ListNode* rev_list(struct ListNode* head) {
    struct ListNode* head0 = NULL;
    struct ListNode* head1 = head;
    struct ListNode* head2 = NULL;

    while (head1 != NULL) {
        head2 = head1->next;
        head1->next = head0;
        head0 = head1;
        head1 = head2;
    }
    return head0;
}
bool isPalindrome(struct ListNode* head) {
    if (!head->next) return true;

    struct ListNode* p1 = head;
    struct ListNode* p2 = head;

    while(p2->next != NULL && p2->next->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    struct ListNode* rev = rev_list(p1->next);
    
    while(rev) {
        if (head->val != rev->val) return false;
        head = head->next;
        rev = rev->next;
    }
    return true;
}
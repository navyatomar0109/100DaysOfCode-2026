struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }   return prev;
}
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* sechalf = reverse(slow);
    struct ListNode* firhalf = head;
    while (sechalf != NULL) {
        if (firhalf->val != sechalf->val) {
            return false;
        }
        firhalf = firhalf->next;
        sechalf = sechalf->next;
    }
    return true;
}
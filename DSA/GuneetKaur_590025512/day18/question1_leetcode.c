struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head ==0|| head->next == 0|| k == 0)
        return head;
    int len = 1;
    struct ListNode *tail = head;

    while (tail->next != 0) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0)
        return head;

    tail->next = head;

    int steps = len - k - 1;
    struct ListNode *newTail = head;

    while (steps--) {
        newTail = newTail->next;
    }

    struct ListNode *newHead = newTail->next;

    newTail->next = 0;

    return newHead;
}
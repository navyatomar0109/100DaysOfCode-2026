struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    struct ListNode *temp = head;
    int count = 1;
    while (temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    k = k % count;
    if (k == 0)
        return head;
    temp->next = head;
    int n = count - k;
    struct ListNode *newtail = head;
    for (int i = 1; i < n; i++)
        newtail = newtail->next;
    struct ListNode *newhead = newtail->next;
    newtail->next = NULL;
    return newhead;
}
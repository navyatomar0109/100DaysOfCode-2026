struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    head->next = deleteDuplicates(head->next);

    if (head->val == head->next->val) {
        struct ListNode *temp = head->next;
        head->next = temp->next;
        free(temp);
    }

    return head;
}

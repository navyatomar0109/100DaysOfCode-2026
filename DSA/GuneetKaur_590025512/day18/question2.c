struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == 0)
        return head;

    struct ListNode *fast = head;
    struct ListNode *slow = head;


    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    if (fast == 0) {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    while (fast->next != 0) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode *temp = slow->next;
    slow->next = temp->next;
    free(temp);

    return head;
}
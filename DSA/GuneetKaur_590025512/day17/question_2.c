//detect cycle

struct ListNode {
    int val;
    struct ListNode *next;
};

void Cycle(struct ListNode *head) {
    if (head == 0|| head->next == 0) {
        printf("false\n");
        return;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != 0 && fast->next != 0) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("true\n");
            return;
        }
    }
    printf("false\n");
}

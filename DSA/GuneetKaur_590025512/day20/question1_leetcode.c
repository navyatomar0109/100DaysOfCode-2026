struct ListNode
{int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *temp = &dummy;

    while (temp->next != 0) {
        if (temp->next->val == val) {
            temp->next = temp->next->next;  
        } else 
            temp = temp->next;
        }
    
    return dummy.next;
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;

        while(current->next != NULL && current->next->next != NULL) {
            ListNode* first = current->next;
            ListNode* second = first->next;
            first->next = second->next;
            second->next = first;
            current->next = second;
            current = first;
        }
        return dummy.next;
    }
};

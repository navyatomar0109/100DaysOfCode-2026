class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newNode = new ListNode(0);
        newNode->next = head;
        ListNode* fast = newNode;
        ListNode* slow = newNode;
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;
        ListNode* newHead = newNode->next;
        delete newNode;
        return newHead;
    }
};
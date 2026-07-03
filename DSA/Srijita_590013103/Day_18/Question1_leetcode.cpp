class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        int length = 1;
        ListNode* curr = head;
        while(curr->next){
            curr = curr->next;
            length++;
        }
        k = k % length;
        if(k == 0)
            return head;
        curr->next = head;
        int steps = length - k - 1;
        ListNode* newTail = head;
        while(steps--){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};
class Solution {
public:
    ListNode* segregateEvenOdd(ListNode* head) {

        if (head == NULL)
            return NULL;

        ListNode *evenHead = NULL, *evenTail = NULL;
        ListNode *oddHead = NULL, *oddTail = NULL;

        ListNode* current = head;

        while (current != NULL) {

            ListNode* nextNode = current->next;
            current->next = NULL;

            if (current->val % 2 == 0) {

                if (evenHead == NULL) {
                    evenHead = evenTail = current;
                } else {
                    evenTail->next = current;
                    evenTail = current;
                }

            } else {

                if (oddHead == NULL) {
                    oddHead = oddTail = current;
                } else {
                    oddTail->next = current;
                    oddTail = current;
                }
            }

            current = nextNode;
        }

        if (evenHead == NULL)
            return oddHead;

        evenTail->next = oddHead;

        return evenHead;
    }
};

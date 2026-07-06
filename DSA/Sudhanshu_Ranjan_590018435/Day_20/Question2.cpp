/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* segregateEvenOdd(ListNode* head) {
        ListNode *evenHead = nullptr, *evenTail = nullptr;
        ListNode *oddHead = nullptr, *oddTail = nullptr;

        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->val % 2 == 0) {
                if (evenHead == nullptr) {
                    evenHead = evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = curr;
                }
            } else {
                if (oddHead == nullptr) {
                    oddHead = oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = curr;
                }
            }
            curr = curr->next;
        }

        if (evenTail != nullptr)
            evenTail->next = oddHead;

        if (oddTail != nullptr)
            oddTail->next = nullptr;

        return (evenHead != nullptr) ? evenHead : oddHead;
    }
};
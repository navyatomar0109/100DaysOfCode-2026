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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        int currentVal = -200;
        while (temp!= nullptr and temp->next != NULL) {
            if (temp->val > currentVal)
                currentVal = temp->val;
            ListNode* nextNode = temp->next;
            if (nextNode->val == currentVal) {
                temp->next = nextNode->next;
                delete nextNode;
            } 
            else {
                temp = temp->next;
            }
        }
        return head;
    }
};
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
        if(!head || !head -> next) return head;
        ListNode* prev = head;
        ListNode* after = head -> next;
        while(after){
            if(prev -> val == after -> val){
                prev -> next = after -> next;
                delete(after);
                after = prev->next;
            }else{
                prev = after;
                after = after -> next;
            }
        }
        return head;
    }
};
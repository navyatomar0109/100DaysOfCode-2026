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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next || k == 0){
            return head;
        }
        int l = 1;
        ListNode* tail = head;
        while(tail -> next != NULL){
            tail = tail -> next;
            l++;
        }
        k = k % l;
        if(k == 0) return head;

        tail -> next = head;
        int remain = l - k;
        ListNode* newTail = head;
        for(int i = 1 ;i < remain; i++){
            newTail = newTail -> next;
        }
        ListNode* newHead = newTail -> next;
        newTail -> next = NULL;

        return newHead;
    }
};
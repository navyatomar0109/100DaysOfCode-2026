/* Leetcode Problem 61
Rotate List */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    struct ListNode *temp = head;
    int length = 1;
    while(temp->next != NULL){
        temp = temp->next;
        length++;
    }
    k = k % length;
    if(k == 0)
        return head;
    temp->next = head;
    temp = head;
    for(int i = 1; i < length - k; i++){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val) {
            struct ListNode* duplicate = curr->next;
            curr->next = duplicate->next;
            free(duplicate);             
        } else {
            curr = curr->next;             
        }
    }
    return head;
}
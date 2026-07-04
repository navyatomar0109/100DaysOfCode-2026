// Leetcode Problem 203
// Remove Linked List Elements 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
     while(head != NULL && head->val == val){
        struct ListNode* NodeToDelete = head;
        head = head->next;
        free(NodeToDelete);
    }
    
    struct ListNode* temp = head;

    while(temp != NULL && temp->next != NULL){
        if(temp->next->val == val){
            struct ListNode* NodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(NodeToDelete);
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
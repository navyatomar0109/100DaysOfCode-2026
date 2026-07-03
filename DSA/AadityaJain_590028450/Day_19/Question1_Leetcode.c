/*Remove Duplicates from Sorted List
Explanation
Remove all duplicate nodes from a sorted linked list so that each value appears only once.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    
    struct ListNode *ptr = head;
    struct ListNode *temp;

    while(ptr != NULL && ptr->next != NULL){
        if(ptr->val == ptr->next->val){
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }else{
            ptr = ptr->next;
        }
    }

    return head;
}
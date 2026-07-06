/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#include <stdio.h>
#include <stdlib.h>


struct ListNode* swapPairs(struct ListNode* head) 
{
    
    if (head == NULL || head->next==NULL)
    return head;

    
    struct ListNode* temp= head;

    while (temp !=NULL && temp->next != NULL)
    {
        int val = temp->val;
        temp->val = temp->next->val;
        temp->next->val = val;

        temp = temp->next->next;
    }
    return head;
}
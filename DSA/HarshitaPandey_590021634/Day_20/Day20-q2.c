#include <stdio.h>
#include <stdlib.h>


struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode* dummy = (struct ListNode*) malloc (sizeof (struct ListNode));
    dummy->val= -1;
    dummy->next= head;

    struct ListNode* temp= dummy;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->val == val)
        {
            struct ListNode* delete = temp->next;
            temp->next = temp->next->next;
            free(delete);
        }

        else
        {
            temp=temp->next;
        }
    }

    struct ListNode* newhead= dummy->next;
    free(dummy);
    return newhead;

}
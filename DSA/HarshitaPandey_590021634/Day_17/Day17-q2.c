//palindrome check

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* middle(struct ListNode* head)
{
    struct ListNode* slow= head;
    struct ListNode* fast= head;

    while (fast != NULL && fast->next !=NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}



struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* prev=NULL;
    struct ListNode* curr= head;
    struct ListNode* next_node=NULL;

    while (curr != NULL)
    {
        next_node = curr->next;
        curr->next = prev;
        prev= curr;
        curr=next_node;
    }
    return prev;
}



bool isPalindrome(struct ListNode* head) 
{
    if (head ==NULL || head->next == NULL)
    {
        return true;
    }


    struct ListNode* mid = middle(head);

    struct ListNode* firsthalf = head;
    struct ListNode* secondhalf = reverse(mid);

    struct ListNode* temp= secondhalf;

    while (temp !=NULL)
    {
        if (firsthalf->val != temp->val)
        {
            return false;
        }
        firsthalf= firsthalf->next;
        temp=temp->next;
    }
    return true;
    
}
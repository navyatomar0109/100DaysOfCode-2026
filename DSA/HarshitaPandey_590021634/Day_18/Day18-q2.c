
#include <stdio.h>
#include <stdlib.h>



struct ListNode {
    int val;
    struct ListNode *next; };  


struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    if (head == NULL || head->next == NULL || k==0)
    {
        return head;
    }


    struct ListNode* tail_node = head;
    int length = 1;
    while (tail_node->next != NULL)
    {
        tail_node = tail_node->next;
        length++;
    }
    

    k = k% length;


    tail_node->next= head;
    int new_tail = length - k;
    struct ListNode* newTail = head;

    for (int i = 1; i < new_tail; i++) 
    {
        newTail = newTail->next;
    }
    
    
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    
    return newHead;

}
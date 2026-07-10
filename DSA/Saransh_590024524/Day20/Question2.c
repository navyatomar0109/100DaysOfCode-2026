#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* segregateEvenOdd(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;
    struct Node *curr = head;

    while (curr != NULL)
    {
        struct Node *nextNode = curr->next;
        curr->next = NULL;

        if (curr->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = curr;
                evenTail = curr;
            }
            else
            {
                evenTail->next = curr;
                evenTail = curr;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = curr;
                oddTail = curr;
            }
            else
            {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = nextNode;
    }

    if (evenHead == NULL)
        return oddHead;

    evenTail->next = oddHead;

    return evenHead;
}
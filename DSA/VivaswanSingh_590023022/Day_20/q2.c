struct Node* segregateEvenOdd(struct Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *next = current->next;
        current->next = NULL;

        if (current->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = evenTail = current;
            }
            else
            {
                evenTail->next = current;
                evenTail = current;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = oddTail = current;
            }
            else
            {
                oddTail->next = current;
                oddTail = current;
            }
        }

        current = next;
    }

    if (evenHead == NULL)
        return oddHead;

    evenTail->next = oddHead;

    return evenHead;
}
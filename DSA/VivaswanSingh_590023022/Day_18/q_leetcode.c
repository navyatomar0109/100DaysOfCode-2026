struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int length = 1;
    struct ListNode *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
        length++;
    }

    k %= length;

    if (k == 0)
        return head;

    tail->next = head;

    int stepsToNewTail = length - k - 1;
    struct ListNode *newTail = head;

    while (stepsToNewTail--)
    {
        newTail = newTail->next;
    }

    struct ListNode *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
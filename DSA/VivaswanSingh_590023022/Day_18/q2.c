struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode *nodeToDelete = slow->next;
    slow->next = nodeToDelete->next;
    free(nodeToDelete);

    return dummy.next;
}
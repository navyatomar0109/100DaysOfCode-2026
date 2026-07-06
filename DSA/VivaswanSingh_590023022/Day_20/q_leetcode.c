struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *current = &dummy;

    while (current->next != NULL)
    {
        if (current->next->val == val)
        {
            struct ListNode *nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            free(nodeToDelete);
        }
        else
        {
            current = current->next;
        }
    }

    return dummy.next;
}
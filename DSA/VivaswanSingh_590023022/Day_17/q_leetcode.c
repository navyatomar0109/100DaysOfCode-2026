bool isPalindrome(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL;
    struct ListNode *curr = slow->next;

    while (curr != NULL)
    {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode *first = head;
    struct ListNode *second = prev;

    while (second != NULL)
    {
        if (first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}
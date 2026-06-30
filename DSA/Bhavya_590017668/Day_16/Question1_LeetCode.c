struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy, *first, *second;

    while (prev->next && prev->next->next) {
        first = prev->next;
        second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    return dummy.next;
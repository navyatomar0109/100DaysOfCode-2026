struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    int n = 1;
    struct ListNode *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
        n++;
    }

    temp->next = head;

    k = k % n;

    int move = n - k;

    while(move > 0)
    {
        temp = temp->next;
        move--;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}

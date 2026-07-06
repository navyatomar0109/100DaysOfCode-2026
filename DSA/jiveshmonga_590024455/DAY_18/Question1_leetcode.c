struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head==NULL||head->next==NULL||k==0)
    {
        return head;
    }
    struct ListNode *temp=head;
    int len=1;

    while(temp->next!=NULL)
    {
        temp=temp->next;
        len++;
    }
    k=k%len;
    if(k==0)
        return head;

    temp->next=head;

    int steps=len-k;
    struct ListNode *newTail=head;

    for(int i=1;i<steps;i++)
    {
        newTail=newTail->next;
    }
    struct ListNode *newHead=newTail->next;
    newTail->next=NULL;
    return newHead;
}

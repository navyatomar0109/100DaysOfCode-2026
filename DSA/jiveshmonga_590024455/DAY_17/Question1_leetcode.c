struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode *prev=NULL;
    struct ListNode *curr=head;
    struct ListNode *next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head)
{
    if(head==NULL||head->next==NULL)
        return true;
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode *second=reverse(slow);
    struct ListNode *first=head;
    while(second!=NULL)
    {
        if(first->val!=second->val)
            return false;
        first=first->next;
        second=second->next;
    }
    return true;
}

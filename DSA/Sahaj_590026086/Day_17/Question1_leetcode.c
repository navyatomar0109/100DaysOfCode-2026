struct ListNode* reverse(struct ListNode* head){
    struct ListNode *prev=NULL,*curr=head,*next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head){
    if(!head||!head->next)
        return true;
    struct ListNode *slow=head, *fast=head;
    while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode* second=reverse(slow->next);
    struct ListNode* first=head;
    while(second){
        if(first->val!=second->val)
            return false;
        first=first->next;
        second=second->next;
    }
    return true;
}

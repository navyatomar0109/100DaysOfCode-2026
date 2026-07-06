 struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode *a =head;
    struct ListNode *b =head;
    while (b!=NULL&&b->next!=NULL) {
        a=a->next;
        b=b->next->next;
    }
    return a;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *temp=head,*prev=NULL;
    if(head==NULL) return head;
    while (head!=NULL && head->val==val) {
        temp=head;
        head=head->next;
        free(temp);
    }
    temp=head;
    while (temp!=NULL) {
        if (temp->val==val) {
            prev->next=temp->next;
            free(temp);
            temp=prev->next;
        }
        else {
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}

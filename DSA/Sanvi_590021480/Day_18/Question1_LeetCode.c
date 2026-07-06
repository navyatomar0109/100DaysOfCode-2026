/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL || head->next==NULL) return head;

    struct ListNode* temp1=head;
    int count=0;
    while(temp1!=NULL){
        count++;
        temp1=temp1->next;
    }
    k=k%count;
    if (k==0) return head;
    for(int i=1;i<=k;i++){
        struct ListNode* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        struct ListNode* last=temp->next;
        last->next=head;
        temp->next=NULL;
        head=last;
    }
    return head;
}

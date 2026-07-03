/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL) return head;
    struct ListNode* tempo=head;
    int total=0;
    while(tempo!=NULL){
        total++;
        tempo=tempo->next;
    }
    k=k%total;
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

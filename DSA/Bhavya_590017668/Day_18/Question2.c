#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val){
    struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val=val;
    newNode->next=NULL;
    return newNode;
}

void printList(struct ListNode* head){
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}

struct ListNode* removeNthFromEnd(struct ListNode* head,int n){
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode *fast=&dummy,*slow=&dummy;
    for(int i=0;i<=n;i++) fast=fast->next;
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    struct ListNode *temp=slow->next;
    slow->next=slow->next->next;
    free(temp);
    return dummy.next;
}

int main(){
    struct ListNode* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);

    int n=2;
    head=removeNthFromEnd(head,n);

    printList(head);
    return 0;
}
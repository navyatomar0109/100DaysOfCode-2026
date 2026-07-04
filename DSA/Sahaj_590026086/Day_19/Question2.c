#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* find(struct Node* head) {
    struct Node *slow=head, *fast=head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *head=NULL, *temp=NULL, *newNode;
    for(int i=0;i<n;i++){
        printf("Enter a number:");
        scanf("%d", &x);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=x;
        newNode->next=NULL;
        if(!head){
            head=newNode;
            temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    struct Node* mid=find(head);
    if(mid)
        printf("Middle element: %d\n", mid->data);
    return 0;
}

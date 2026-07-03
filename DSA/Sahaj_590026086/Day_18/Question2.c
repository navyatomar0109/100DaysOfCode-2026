#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* remove(struct Node* head, int n) {
    struct Node dummy;
    dummy.next=head;
    struct Node *fast=&dummy,*slow=&dummy;
    for(int i=0;i<=n;i++){
        fast=fast->next;
    }
    while(fast){
        fast=fast->next;
        slow=slow->next;
    }
    struct Node* del=slow->next;
    slow->next=del->next;
    free(del);
    return dummy.next;
}
void display(struct Node* head){
    while(head){
        printf("%d ", head->data);
        head=head->next;
    }
}
int main() {
    int n, x, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *head=NULL,*temp=NULL,*newNode;
    for(int i=0;i<n;i++){
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
    printf("Enter n: ");
    scanf("%d", &k);
    head=remove(head, k);
    printf("Updated list:\n");
    display(head);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* removerear(struct Node* head){
    if(head==NULL) 
      return NULL;
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return head;
}
void display(struct Node* head){
    while(head!=NULL){
        printf("%d ", head->data);
        head=head->next;
    }
}
int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *head=NULL,*temp=NULL,*newNode;
    for(int i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->prev=temp;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
        } 
        else{
            temp->next=newNode;
        }
        temp=newNode;
    }
    head=removerear(head);
    printf("Updated list:\n");
    display(head);
    return 0;
}

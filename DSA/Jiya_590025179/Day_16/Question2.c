#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node* next;
  struct node* prev;
};

struct node* createnode(int value){
  struct node*n=malloc(sizeof(struct node));
  n->data=value;
  n->next=NULL;
  n->prev=NULL;
  return n;
}

struct node* insert(struct node* head,int value){
    struct node* newnode=createnode(value);
    if(head==NULL){  
        return newnode;
    }

    struct node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}

struct node* deletenode(struct node* head){
  if(head==NULL) return NULL;
  if (head->next==NULL){
    free(head);
    return NULL;
  }

  struct node* temp=head;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  free(temp->next);
  temp->next=NULL;
  return head;
}
void print(struct node* head){
    struct node* temp=head;
   
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){

  struct node* head=NULL;
  int value;
  char choice;

  do{
    printf("Enter data: ");
    scanf("%d",&value);
    head=insert(head,value);
    printf("Add another node? Enter (Y/N): ");
    scanf(" %c",&choice);

  }while(choice=='Y' || choice=='y');
  head=deletenode(head);
  print(head);
  return 0;
}

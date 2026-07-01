#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* createNode(int value){
  struct node*n=malloc(sizeof(struct node));
  n->data=value;
  n->next=NULL;
  return n;
}

struct node* insertEnd(struct node* head, int value){
  struct node* newNode=createNode(value);
  if(head==NULL) return newNode;

  struct node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=newNode;
  return head;
}

int hasCycle(struct node *head) {
    struct node* slow=head;
    struct node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
          return 1;
        }
    }
    return 0;
}


int main(){

  struct node* head=NULL;
  int value;
  char choice;

  do{
    printf("Enter value: ");
    scanf("%d",&value);
    head=insertEnd(head,value);
    printf("Add another node? (Y/N): ");
    scanf(" %c",&choice);

  }while(choice=='Y');
  int pos;
  printf("Enter position: ");
  scanf("%d",&pos);

  if(pos!=-1){
    struct node* last=head;
    struct node* cycle=NULL;
    int index=0;

    while(last->next!=NULL){
      if(index==pos) cycle=last;
      last=last->next;
      index++;
    }
    if(index==pos) cycle=last;

    if(cycle!=NULL) last->next=cycle;
  }

  if (hasCycle(head))
  printf("true");
  else
  printf("false");

  return 0;
}

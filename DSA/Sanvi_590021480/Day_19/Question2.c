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

struct node* middleNode(struct node* head) {
    struct node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int key=(count/2)+1;
        temp=head;
        for(int i=1;i<key;i++){
            temp=temp->next;
        }
       
    return temp;
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

  head=middleNode(head);
  printf("%d",head->data);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
}*temp;

struct node* createnode(int value) {
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=value;
    n->next=NULL;
    return n;
}
struct node* insertlast(struct node* head, int value) {
    struct node* newnode=createnode(value);

    if (head==NULL) return newnode;
    struct node* temp=head;
    while (temp->next!=NULL) temp=temp->next;
    temp->next=newnode;
    return head;
}
int main() {
    struct node* head=NULL;
    int value,count=0;
    char choice;

    do {
        printf("Enter value: ");
        scanf("%d", &value);
        head=insertlast(head, value);
        count++;
        printf("Add another node? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');
    
    if(count==0) return 0;
    else if(count==1) printf("%d", head->data);
    else if(count%2!=0) {
        temp=head;
        for(int i=0;i<count/2;i++) temp=temp->next;
        printf("%d",temp->data);
    }
    else {
        temp=head;
        for(int i=0;i<count/2-1;i++) temp=temp->next;
        printf("%d, %d",temp->data,temp->next->data);
    }
    
    
    return 0;
}

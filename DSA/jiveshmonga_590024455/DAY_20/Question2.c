#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insert(struct Node** head, int data) {
    struct Node* newNode=createNode(data);
    if (*head == NULL) 
    {
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while (temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
}

void segregateEvenOdd(struct Node** head) {
    struct Node *evenStart=NULL,*evenEnd=NULL;
    struct Node *oddStart=NULL,*oddEnd=NULL;
    struct Node *curr=*head;
    while (curr != NULL) 
    {
        int val=curr->data;
        if(val%2==0) 
        {   
            if (evenStart==NULL) 
            {
                evenStart=curr;
                evenEnd=evenStart;
            } 
            else 
            {
                evenEnd->next=curr;
                evenEnd=evenEnd->next;
            }
            }
            else 
            {   
            if (oddStart==NULL) 
            {
                oddStart=curr;
                oddEnd = oddStart;
            } 
            else 
            {
                oddEnd->next=curr;
                oddEnd=oddEnd->next;
            }
        }
        curr = curr->next;
    }
    if (evenStart==NULL||oddStart==NULL)
        return;
    evenEnd->next=oddStart;
    oddEnd->next=NULL;
    *head = evenStart;
}

void display(struct Node* head) {
    while (head!=NULL) 
    {
        printf("%d",head->data);
        if (head->next!=NULL)
            printf(" -> ");
        head = head->next;
    }
}

int main() 
{
    struct Node* head=NULL;
    insert(&head,17);
    insert(&head,15);
    insert(&head,8);
    insert(&head,9);
    insert(&head,2);
    insert(&head,4);
    insert(&head,6);
    segregateEvenOdd(&head);
    display(head);
    return 0;
}
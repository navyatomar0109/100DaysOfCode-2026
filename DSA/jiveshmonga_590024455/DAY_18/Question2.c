#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void printList(struct Node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
struct Node* removeNthFromEnd(struct Node* head, int n)
{
    int count=0;
    struct Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    if(count==n)
    {
        temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    temp=head;
    for(int i=1;i<count-n;i++)
    {
        temp=temp->next;
    }
    struct Node* del=temp->next;
    temp->next=del->next;
    free(del);
    return head;
}
int main()
{
    struct Node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);

    int n=2;
    head=removeNthFromEnd(head,n);
    printList(head);
    return 0;
}

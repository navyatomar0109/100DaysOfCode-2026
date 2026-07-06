/*  Q1: Find and return the middle node of a singly linked list; if there are two middle nodes, 
return the second one.

Example:
Input:head = [1,2,3,4,5]; Output:3   */


#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};


struct node* createnode(int data) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}



struct node* findmiddlenode (struct node* head)
{
    struct node* slow = head;
    struct node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}



int main()
{
    int n;
    struct node* head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct node* newnode = createnode(data);
        if (head == NULL)
        {
            head = newnode;
        }

        else
        {
            struct node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    struct node* middle = findmiddlenode(head);
    printf("Middle node value: %d\n", middle->data);

    return 0;
}

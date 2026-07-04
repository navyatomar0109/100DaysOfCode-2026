/*  Q1: Rearrange the existing linked list so that all even valued nodes appear before odd valued nodes 
while preserving their original order, without creating a new linked list, 
and print the modified linked list.

Example:
Input:17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6;  Output:8 -> 2 -> 4 -> 6 -> 17 -> 15 -> 9   */

#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* next;
};


struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}



struct node* rearrange(struct node* head)
{
    struct node* evenStart = NULL;
    struct node* evenEnd = NULL;

    struct node* oddStart = NULL;
    struct node* oddEnd = NULL;

    struct node* current = head;

    while (current != NULL)
    {
        if (current->data %2 == 0)
      {
        if (evenStart == NULL)
        {
            evenStart = current;
            evenEnd = evenStart;
        }

        else
        {
            evenEnd->next = current;
            evenEnd = evenEnd->next;
        }
    }


    else 
    {
        if (oddStart == NULL)
        {
            oddStart = current;
            oddEnd = oddStart;
        }

        else
        {
            oddEnd->next = current;
            oddEnd = oddEnd->next;
        }
    }

    current= current->next;
}

    if (evenEnd != NULL)
    {
        evenEnd->next = oddStart;
    }

    if (oddEnd != NULL)
    {
        oddEnd->next = NULL;
    }

    return evenStart;
}



void display(struct node* evenStart)
{
    struct node* temp = evenStart;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main()
{
    int n, data;
    struct node* head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
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

    head= rearrange(head);

    printf("Modified linked list: ");
    display(head);
    return 0;
}
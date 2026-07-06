/*  Determine whether a singly linked list contains a cycle (loop); return true if a cycle exists, 
otherwise return false. Here, pos represents the index of the node that the last node points to 
(-1 means the last node points to NULL).

Example:
Input:head = [3,2,0,-4]; pos = 1. Output:true   */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node
{
    int data;
    struct node *next;
};


struct node *createnode(struct node *head, int val)
{
    struct node* newnode = (struct node*) malloc (sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;

}




bool Loop (struct node* head)
{
    struct node* slow= head;
    struct node* fast= head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == fast)
    {
        return true;
    }

    else
    {
        return false;
    }

}





int main()
{
    int n, result;
    struct node* head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);

        struct node* newnode = createnode(head, val);

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

    result = Loop(head);
    if (result)
    {
        printf("The linked list contains a cycle.\n");
    }
    else
    {
        printf("The linked list does not contain a cycle.\n");
    }

    return 0;
}
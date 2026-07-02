/* Q1: Remove the nth node from the end of a singly linked list and print the updated linked list.

Example:
Input:head = [1,2,3,4,5]; n = 2. Output:[1,2,3,5]   */


#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};


struct node* delete_end(struct node* head, int N)
{
    for (int i = 0; i < N; i++)
    {
        struct node* temp = head;
        struct node* prev = NULL;

        if (head == NULL)
        {
            return head;
        }
        
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL)
        {
            head = head->next;
            free(temp);
        }

        else
        {
            prev->next = NULL;
            free(temp);
        }
    }
    
    return head;
}




int main()
{
    int n;
    struct node* head = NULL;

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &new_node->data);

        new_node->next = head;
        head = new_node;

        if (head == NULL)
        {
            head = new_node;
        }

        else 
        {
            struct node* temp = head;
            while (temp->next != NULL)
            {
                temp= temp->next;
            }

            temp->next = new_node;
        }
    }
    
    head = delete_end(head, 2);

    return 0;
}
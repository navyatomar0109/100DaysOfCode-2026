/*Delete the last node from a doubly linked list, print the updated list, 
or return NULL if the list becomes empty.

Example:
Input:1 <-> 2 <-> 3 <-> 4; Output:1 <-> 2 <-> 3    */


#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* next;
    struct node* prev;
};



struct node* delete_end(struct node* head)
{
    struct node* temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }


    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        free(temp);
    }
    return head;

}




void display(struct node* head)
{
    struct node* temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d <->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}



int main()
{
    int n;
    struct node* head = NULL;
    
    printf("enter n: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &new_node->data);

        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL)
        {
            head = new_node;
        }

        else
        {
            struct node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }

    }

    head = delete_end(head);
    display(head);

    return 0;
}
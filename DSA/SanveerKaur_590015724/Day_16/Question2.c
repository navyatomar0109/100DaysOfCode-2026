#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Delete the last node
struct Node* deleteLast(struct Node *head)
{
    // Empty list
    if (head == NULL)
        return NULL;

    // Only one node
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node *temp = head;

    // Reach the last node
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);

    return head;
}

// Display the list
void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" <-> ");

        head = head->next;
    }
    printf("\n");
}

int main()
{
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = tail;

        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
    }

    printf("Original List:\n");
    
    display(head);

    head = deleteLast(head);

    printf("After Deleting Last Node:\n");
    display(head);

    return 0;
}
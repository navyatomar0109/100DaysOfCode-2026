#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to reverse the linked list
struct Node* reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;   // Save next node
        curr->next = prev;   // Reverse the link
        prev = curr;         // Move prev forward
        curr = next;         // Move curr forward
    }

    return prev;
}

// Function to display the linked list
void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf(" -> NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    head = reverseList(head);

    printf("Reversed Linked List:\n");
    display(head);

    return 0;
}
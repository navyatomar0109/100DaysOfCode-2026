// Remove Nth Node From End of Linked List


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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

struct Node *removeNthFromEnd(struct Node *head, int n)
{
    struct Node dummy;
    dummy.next = head;

    struct Node *fast = &dummy;
    struct Node *slow = &dummy;

    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    struct Node *deleteNode = slow->next;
    slow->next = deleteNode->next;
    free(deleteNode);

    return dummy.next;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int size, value, n;

    printf("Enter number of nodes: ");
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Enter n: ");
    scanf("%d", &n);

    head = removeNthFromEnd(head, n);

    printf("Updated Linked List: ");
    printList(head);

    return 0;
}
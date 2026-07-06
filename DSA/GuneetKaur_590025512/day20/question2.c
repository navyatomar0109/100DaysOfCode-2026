#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* segregateEvenOdd(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;
    struct Node *curr = head;

    while (curr != NULL)
    {
        struct Node *next = curr->next;
        curr->next = NULL;

        if (curr->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = evenTail = curr;
            }
            else
            {
                evenTail->next = curr;
                evenTail = curr;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = oddTail = curr;
            }
            else
            {
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = next;
    }

    if (evenHead == NULL)
        return oddHead;

    evenTail->next = oddHead;
    return evenHead;
}

struct Node* insert(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int n, x;
    struct Node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }

    head = segregateEvenOdd(head);

    printList(head);

    return 0;
}
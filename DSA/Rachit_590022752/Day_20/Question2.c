#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *head = NULL, *tail = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;
    struct Node *temp = head;

    while (temp != NULL)
    {
        struct Node *nextNode = temp->next;
        temp->next = NULL;

        if (temp->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = temp;
            }
        }

        temp = nextNode;
    }

    if (evenHead == NULL)
    {
        head = oddHead;
    }
    else
    {
        evenTail->next = oddHead;
        head = evenHead;
    }

    printf("Modified Linked List: ");

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}

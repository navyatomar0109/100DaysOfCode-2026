#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int heroID;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int id)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->heroID = id;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->heroID);
        temp = temp->next;
    }

    printf("NULL\n");
}

void deleteHero(int id)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->heroID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
}

struct Node *findMiddle()
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int detectLoop()
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
    }
    return 0;

int main()
    insert(1);
    insert(3);
    insert(4);
    insert(5);

    display();
    display();

    struct Node *mid = findMiddle();

        printf("Backup Leader: %d\n", mid->heroID);

    if (detectLoop())
        printf("Loop Detected\n");
        printf("No Loop\n");

    return 0;
}    else
    if (mid)

    deleteHero(3);

    insert(2);
{
}



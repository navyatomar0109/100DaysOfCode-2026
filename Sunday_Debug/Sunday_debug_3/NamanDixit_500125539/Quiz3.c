#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int heroID;
    struct Node *next;
};

// Head of the linked list
struct Node *head = NULL;

// Insert a new node at the end of the list
void insert(int id)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->heroID = id;
    newNode->next = NULL;

    // If list is empty, new node becomes head
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display the linked list
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

// Delete a node with the given hero ID
void deleteHero(int id)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    // Search for the node
    while (temp != NULL && temp->heroID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    // Hero not found
    if (temp == NULL)
        return;

    // Deleting the first node
    if (prev == NULL)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
}

// Find the middle node using slow and fast pointers
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

// Detect and remove a loop using Floyd's Algorithm
void detectAndRemoveLoop()
{
    struct Node *slow = head;
    struct Node *fast = head;

    // Detect loop
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No loop found
    if (fast == NULL || fast->next == NULL)
        return;

    slow = head;

    // Loop starts at head
    if (slow == fast)
    {
        while (fast->next != slow)
            fast = fast->next;

        fast->next = NULL;
        return;
    }

    // Find the node just before the start of the loop
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the loop
    fast->next = NULL;
}

int main()
{
    // Insert heroes
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    // Create a loop for testing (5 -> 3)
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head->next->next;

    // Remove the loop
    detectAndRemoveLoop();

    // Display the corrected list
    display();

    // Delete hero 3
    deleteHero(3);

    display();

    // Find the backup leader (middle node)
    struct Node *mid = findMiddle();

    if (mid != NULL)
        printf("Backup Leader: %d\n", mid->heroID);

    return 0;
}

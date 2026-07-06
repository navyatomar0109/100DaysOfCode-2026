#include <stdio.h>
#include <stdlib.h>

struct Node {
    int heroID;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at the end
void insert(int id) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->heroID = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display the linked list
void display() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->heroID);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Delete a hero by ID
void deleteHero(int id) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->heroID != id) {
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

// Find the middle node
struct Node *findMiddle() {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Fix accidental loop in the linked list
void fixLoop() {
    if (head == NULL)
        return;

    struct Node *slow = head;
    struct Node *fast = head;

    // Detect loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return; // No loop

    // Find start of loop
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Find last node in loop
    struct Node *ptr = slow;
    while (ptr->next != slow)
        ptr = ptr->next;

    ptr->next = NULL;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    // Ensure list ends with NULL
    fixLoop();

    display();

    deleteHero(3);

    display();

    struct Node *mid = findMiddle();

    if (mid != NULL)
        printf("Backup Leader: %d\n", mid->heroID);

    return 0;
}

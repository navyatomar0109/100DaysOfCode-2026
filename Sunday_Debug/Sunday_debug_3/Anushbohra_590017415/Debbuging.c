#include <stdio.h>
#include <stdlib.h>

struct Node {
    int heroID;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->heroID = id;
    newNode->next = NULL; // Explicitly terminate the new node

    // FIX: Properly handle inserting into an empty list
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display() {
    struct Node* temp = head;

    // FIX: Loop until the end of the list (NULL)
    while (temp != NULL) {
        printf("%d -> ", temp->heroID);
        temp = temp->next;
    }

    printf("NULL\n");
}

void deleteHero(int id) {
    struct Node* temp = head;
    struct Node* prev = NULL;

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

    // FIX: Free the target node (temp), not the previous node
    free(temp); 
}

struct Node* findMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;

    // FIX: Fast pointer must leapfrog two nodes at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next; 
    }

    return slow;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    printf("Initial roster:\n");
    display();

    printf("\nDeleting Hero 3...\n");
    deleteHero(3);
    display();

    struct Node* mid = findMiddle();

    if (mid)
        printf("\nBackup Leader (Middle): %d\n", mid->heroID);

    return 0;
}
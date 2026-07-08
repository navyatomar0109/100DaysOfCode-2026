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
    newNode->next = NULL; // Crucial: terminate the new node properly

    if (head == NULL) {
        head = newNode; // Fix: Assign to head if list is empty
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
    // Fix: Loop until temp reaches NULL, not head
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

    if (temp == NULL) return; // Hero not found

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    
    free(temp); // Fix: Free the target node (temp), not prev!
}

struct Node* findMiddle() {
    if (head == NULL) return NULL;
    
    struct Node* slow = head;
    struct Node* fast = head;

    // Fix: Move fast by two steps each iteration
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
    display();      // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    
    deleteHero(3);
    display();      // Expected: 1 -> 2 -> 4 -> 5 -> NULL

    struct Node* mid = findMiddle();
    if (mid) {
        printf("Backup Leader: %d\n", mid->heroID); // Expected: 4
    }
    return 0;
}
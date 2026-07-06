#include <stdio.h>
#include <stdlib.h>

struct Node {
    int heroID;
    struct Node* next;
};

struct Node* head = NULL;

// Insert a new hero at the end of the roster, preserving arrival order
void insert(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->heroID = id;
    newNode->next = NULL;              // FIX: terminate the new node properly

    if (head == NULL) {
        head = newNode;                // FIX: actually attach first node to head
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Print the full roster in order
void display() {
    struct Node* temp = head;
    while (temp != NULL) {             // FIX: stop at NULL, not back at head
        printf("%d -> ", temp->heroID);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Remove a hero who is no longer on the active roster
void deleteHero(int id) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->heroID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;                        // hero not found, nothing to delete

    if (prev == NULL)
        head = head->next;             // deleting the head node
    else
        prev->next = temp->next;       // bypass the node being deleted

    free(temp);                        // FIX: free the deleted node, not prev
}

// Find the middle hero using the tortoise-and-hare technique
struct Node* findMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;       // FIX: fast must move two steps, not one
    }
    return slow;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();

    deleteHero(3);
    display();

    struct Node* mid = findMiddle();
    if (mid)
        printf("Backup Leader: %d\n", mid->heroID);

    return 0;
}

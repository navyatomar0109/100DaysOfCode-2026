#include <stdio.h>
#include <stdlib.h>

struct Node {
    int heroID;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at end
void insert(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->heroID = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display list
void display() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->heroID);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Delete hero
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

    free(temp);
}

// Find middle hero
struct Node* findMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Detect and remove loop
void detectAndRemoveLoop() {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            fast->next = NULL;
            printf("Loop detected and removed.\n");
            return;
        }
    }

    printf("No loop found.\n");
}

int main() {

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    // Create a loop for testing
    struct Node* temp = head;
    struct Node* third = NULL;

    while (temp->next != NULL) {
        if (temp->heroID == 3)
            third = temp;
        temp = temp->next;
    }

    temp->next = third;

    detectAndRemoveLoop();

    display();

    deleteHero(3);

    display();

    struct Node* mid = findMiddle();

    if (mid)
        printf("Backup Leader: %d\n", mid->heroID);

    return 0;
}

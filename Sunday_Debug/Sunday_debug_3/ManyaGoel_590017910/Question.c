#include <stdio.h>
#include <stdlib.h>

struct Node {
    int heroID;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->heroID = id;
    newNode->next = NULL;              // FIX: must initialize next, otherwise it holds garbage memory  and traversal can loop forever.

    if (head == NULL) {
        head = newNode;                // FIX: the first hero inserted should become the head of the list, otherwise it will be lost and cause a memory leak.                             
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display() {
    struct Node* temp = head;

    while (temp != NULL) {             // FIX: previously it was "temp != head", which is false the instant temp is assigned,so nothing ever printed
        printf("%d -> ", temp->heroID);
        temp = temp->next;
    }

    printf("NULL\n");
}
//FIX: Function to detect and remove a loop in the linked list using Floyd's Cycle Detection Algorithm
void detectAndRemoveLoop() {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return;

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
}


void deleteHero(int id) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->heroID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;                        // FIX:hero not found, nothing to delete

    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);                        // FIX: was "free(prev)" freed the PREVIOUS node and leaked the node we actuallywanted to remove. Must free temp, the node that matched the id.
}

struct Node* findMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;       // FIX: was "fast = fast->next", which made fast move at the SAME speed as slow, so slow landed on the last node instead of the middle. Fast must move two steps for every one step of slow.
    }

    return slow;
}
// Function to free the entire linked list and prevent memory leaks
void freeList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next; 
        free(temp);
        temp = nextNode;
    }
    head = NULL;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    detectAndRemoveLoop(); //FIX: Ensure no loop exists before displaying

    display();

    deleteHero(3);

    display();

    struct Node* mid = findMiddle();

    if (mid)
        printf("Backup Leader: %d\n", mid->heroID);
    

    freeList(); //FIX: System teardown: clean up heap memory
    

    return 0;
}
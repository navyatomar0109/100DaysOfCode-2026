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
    newNode->next = NULL; // Fix 1 - Added this line so that the next pointer for the newNode(now the last node of the list) created is NULL and hence the list terminates properly and prevent infinite loops.

    if (head == NULL) {
        head = newNode; // Fix 2 - Added this line so that when the list is empty, the newNode becomes the head and the list is created. In the original code, if the list was empty, the code would skip the node insertion.
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display() {
    struct Node* temp = head;

    // Fix - 3
    // Original condition - while (temp != head)
    // As we initialized the temp as head above, (temp != head) is false, the loop will never execute and no elements will be printed.
    // Changed the condition to while (temp != NULL) so that it traverses through the whole list and prints the list.
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

    //Fix - 4
    // Origially it was free(prev). But the node that was deleted is stored in temp. So changed it to free(temp) so that it frees the correct memory space.
    free(temp);  
}

struct Node* findMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;

        // Fix - 5
        // Original line - fast = fast->next, but while finding the middle of a linked list, fast pointer should move two steps at a time. So changed it to fast = fast->next->next so that it jumps 2 steps at a time.
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

    display();

    deleteHero(3);

    display();

    struct Node* mid = findMiddle();

    if (mid)
        printf("Backup Leader: %d\n", mid->heroID);

    return 0;
}
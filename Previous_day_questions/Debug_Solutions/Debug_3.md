<h2 align="center">Week 3 Day 21 (05/07/2026) — Weekly Debug 3</h2>

## 1. The Avengers Assembly Glitch

### Solution

```c
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
    // BUG: The next pointer was never initialized.
    newNode->next = NULL;
    // BUG: When the list was empty, the new node was not assigned as the head.
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node* temp = head;
    // BUG: The loop condition used temp != head, so it never printed any node.
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
    // BUG: The previous node was freed instead of the deleted node.
    free(temp);
}

struct Node* findMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;
    // BUG: The fast pointer moved only one step instead of two,
    // preventing the slow pointer from reaching the middle.
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
    display();
    deleteHero(3);
    display();
    struct Node* mid = findMiddle();
    if (mid)
        printf("Backup Leader: %d\n", mid->heroID);
    return 0;
}
```

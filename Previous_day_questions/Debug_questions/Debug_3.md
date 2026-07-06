<h2 align="center">Week 3 Day 21 (05/07/2026) — Weekly Debug 3</h2>

## 1. The Avengers Assembly Glitch

S.H.I.E.L.D.'s supercomputer has been tasked with assembling the Avengers in the correct order for the mission briefing. Each hero is a node in a linked list. Tony Stark at the front, the others chained behind him in order of arrival.

But something went wrong during the data transfer from the Helicarrier.

Some heroes are missing from the chain entirely. Others are linked to the wrong next hero. The last node never points to NULL meaning the list loops forever and Fury's system crashes every time it tries to print the roster.

Nick Fury has a few minutes before the mission goes live. The linked list is broken. The Avengers can't assemble.

Fix the linked list before Thanos does.

This problem is commonly asked in interviews and helps build concepts like:
- Linked list traversal
- Node insertion
- Cycle/loop detection
- Two-pointer technique

which are important for writing correct and reliable programs.

**Your task:** Identify and fix all bugs in the given code so that it produces the correct output.

### What the Code Must Do

- Correctly insert heroes into the linked list.
- Traverse and print the full roster in order.
- Detect and fix the node that never terminates.
- Delete a hero who is no longer on the active roster.
- Find and return the middle hero of the chain (S.H.I.E.L.D. needs the backup leader).

### Constraints

- 1 <= Number of heroes <= 100
- Hero IDs are positive integers.
- Linked list must maintain insertion order at all times.
- Correct the existing implementation. Do not rewrite using another data structure.

### Examples

**Input:**
```
(Buggy code with the following functions)
insert(id), display(), deleteHero(id), findMiddle()
```
**Output:**
```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
1 -> 2 -> 4 -> 5 -> NULL
Backup Leader: 4
```

### Buggy Code

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
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node* temp = head;
    while (temp != head) {
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
    free(prev);
}

struct Node* findMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
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

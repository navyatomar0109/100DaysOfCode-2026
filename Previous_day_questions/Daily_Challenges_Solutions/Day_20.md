<h2 align="center">Week 3 Day 20 (04/07/2026)</h2>

## 1. Remove Linked List Elements (LeetCode #203)

### Solution

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create an extra node to handle deletion of the head node easily
    struct ListNode start;
    start.next = head;
    // Pointer to traverse the list
    struct ListNode *current = &start;
    // Traverse the linked list
    while (current->next != NULL) {
        // If the next node contains the value to be removed
        if (current->next->val == val) {
            struct ListNode *temp = current->next;  // Node to delete
            current->next = temp->next;             // Skip the node
            free(temp);                             // Free memory
        } else {
            // Move to the next node
            current = current->next;
        }
    }
    // Return the updated head
    return start.next;
}
```

---

## 2. Segregate Even and Odd Nodes in a Linked List

### Solution

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Rearrange the linked list so that even-valued nodes come before odd-valued nodes
struct Node* segregateEvenOdd(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;
    struct Node *current = head;

    while (current != NULL) {
        struct Node *nextNode = current->next;
        current->next = NULL;

        // Add even node to the even list
        if (current->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        }
        // Add odd node to the odd list
        else {
            if (oddHead == NULL) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = nextNode;
    }

    // If there are no even nodes
    if (evenHead == NULL)
        return oddHead;

    // Connect even list with odd list
    evenTail->next = oddHead;
    return evenHead;
}

// Print the linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    // Take input and create the linked list as per requirement
    head = segregateEvenOdd(head);
    // Print the rearranged linked list
    printList(head);
    return 0;
}
```

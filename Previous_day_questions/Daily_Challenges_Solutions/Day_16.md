<h2 align="center">Week 3 Day 16 (30/06/2026)</h2>

## 1. Swap Nodes In Pairs (LeetCode #24)

### Solution

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    // If the list is empty or has only one node, no swapping is needed
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // Initialize pointers for adjacent nodes
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    // Traverse the list two nodes at a time
    while (fast != NULL) {
        // Swap the values of the adjacent nodes
        int temp = fast->val;
        fast->val = slow->val;
        slow->val = temp;
        // Move slow to the next pair
        slow = fast->next;
        // Check if another pair exists
        if (fast->next == NULL) {
            fast = NULL;
        }
        else {
            // Move fast to the second node of the next pair
            fast = fast->next->next;
        }
    }
    // Return the modified linked list
    return head;
}
```

---

## 2. Delete Last Node of a Doubly Linked List

### Solution

```c
#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to delete the last node
struct Node* deleteLastNode(struct Node *head) {
    // If the list is empty
    if (head == NULL)
        return NULL;
    // If the list contains only one node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    // Traverse to the last node
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Remove the last node from the list
    temp->prev->next = NULL;
    // Free the memory of the deleted node
    free(temp);
    // Return the updated head
    return head;
}

// Function to print the linked list
void printList(struct Node *head) {
    // If the list is empty
    if (head == NULL) {
        printf("NULL");
        return;
    }
    // Print all nodes
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    // Create first node
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    // Create second node
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    second->data = 20;
    // Connect the two nodes
    head->prev = NULL;
    head->next = second;
    second->prev = head;
    second->next = NULL;
    printf("Original List: ");
    printList(head);
    // Delete the last node
    head = deleteLastNode(head);
    printf("\nUpdated List: ");
    printList(head);
    return 0;
}
```

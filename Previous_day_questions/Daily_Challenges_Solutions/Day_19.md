<h2 align="center">Week 3 Day 19 (03/07/2026)</h2>

## 1. Remove Duplicates from Sorted List (LeetCode #83)

### Solution

```c
/**
 * Definition for a singly linked list node.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Start traversing from the head of the linked list
    struct ListNode* curr = head;
    // Traverse until the end of the list
    while (curr != NULL && curr->next != NULL) {
        // If the current node and next node have the same value,
        // remove the duplicate node by skipping it
        if (curr->val == curr->next->val) {
            curr->next = curr->next->next;
        }
        // Otherwise, move to the next node
        else {
            curr = curr->next;
        }
    }
    // Return the head of the updated linked list
    return head;
}
```

---

## 2. Middle of the Linked List

### Solution

```c
#include <stdio.h>
#include <stdlib.h>

// Structure for a singly linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to find the middle node
struct Node* findMiddle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;
    // Move slow by one step and fast by two steps
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Slow will point to the middle node
    return slow;
}

int main() {
    struct Node *head = NULL;
    /*
        Take input as per your requirement.
        Example:
        Input:
        5
        1 2 3 4 5
        or create the linked list manually.
    */
    struct Node *middle = findMiddle(head);
    if (middle != NULL)
        printf("%d\n", middle->data);
    else
        printf("Linked list is empty.\n");
    return 0;
}
```

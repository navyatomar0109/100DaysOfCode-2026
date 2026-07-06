<h2 align="center">Week 3 Day 18 (02/07/2026)</h2>

## 1. Rotate List (LeetCode #61)

### Solution

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    // Find the length of the linked list
    int len = 1;
    struct ListNode *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }
    // Reduce unnecessary rotations
    k = k % len;
    if (k == 0)
        return head;
    // Make the linked list circular
    tail->next = head;
    // Find the new tail
    int steps = len - k;
    struct ListNode *newTail = head;
    while (--steps) {
        newTail = newTail->next;
    }
    // Set the new head
    struct ListNode *newHead = newTail->next;
    // Break the circular link
    newTail->next = NULL;
    return newHead;
}
```

---

## 2. Remove Nth Node From End of Linked List

### Solution

```c
#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to remove the nth node from the end
struct Node* removeNthFromEnd(struct Node *head, int n) {
    // Create a temporary node to handle deletion of the head node
    struct Node *tempHead = (struct Node *)malloc(sizeof(struct Node));
    tempHead->next = head;
    struct Node *fast = tempHead;
    struct Node *slow = tempHead;
    // Move the fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    // Delete the required node
    struct Node *temp = slow->next;
    slow->next = temp->next;
    free(temp);
    head = tempHead->next;
    free(tempHead);
    return head;
}

// Function to print the linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int n;
    // Input and linked list creation can be coded here as per the required input format.
    scanf("%d", &n);
    head = removeNthFromEnd(head, n);
    printList(head);
    return 0;
}
```

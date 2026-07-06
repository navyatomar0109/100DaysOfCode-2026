<h2 align="center">Week 3 Day 17 (01/07/2026)</h2>

## 1. Palindrome Linked List (LeetCode #234)

### Solution

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while (curr != NULL) {
        struct ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    // Empty list or single node is always a palindrome
    if (head == NULL || head->next == NULL)
        return true;
    // Find the middle of the linked list
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse the second half
    struct ListNode *secondHalf = reverseList(slow);
    // Compare both halves
    struct ListNode *firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}
```

---

## 2. Detect Cycle in a Linked List

### Solution

```c
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to check whether the linked list contains a cycle
int hasCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;
    // Traverse the linked list
    while (fast != NULL && fast->next != NULL) {
        // Move slow pointer one step
        slow = slow->next;
        // Move fast pointer two steps
        fast = fast->next->next;
        // If both pointers meet, a cycle exists
        if (slow == fast) {
            return 1;
        }
    }
    // No cycle found
    return 0;
}

int main() {
    struct Node *head = NULL;
    // Create linked list here
    // (Input code can be added as per requirement)
    if (hasCycle(head))
        printf("Cycle exists\n");
    else
        printf("No cycle exists\n");
    return 0;
}
```

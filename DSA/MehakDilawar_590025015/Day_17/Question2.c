//Determine whether a singly linked list contains a cycle (loop);
//return true if a cycle exists, otherwise return false. 
//Here, pos represents the index of the node that the last node points to (-1 means the last node points to NULL).
//Input:head = [3,2,0,-4], pos = 1. Output = true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//Floyd's algorithm
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    int n, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("List is empty.\n");
        return 0;
    }

    struct ListNode *head = NULL, *tail = NULL, *nodes[n];
    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        nodes[i] = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d", &nodes[i]->val);
        nodes[i]->next = NULL;

        if (head == NULL)
            head = tail = nodes[i];
        else {
            tail->next = nodes[i];
            tail = nodes[i];
        }
    }

    printf("Enter pos (-1 for no cycle): ");
    scanf("%d", &pos);

    if (pos >= 0 && pos < n) {
        tail->next = nodes[pos];
    }
    if (hasCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (!head || !head->next) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct ListNode* head = createNode(3);
    struct ListNode* node2 = createNode(2);
    struct ListNode* node3 = createNode(0);
    struct ListNode* node4 = createNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; 

    if (hasCycle(head)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    free(head);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}
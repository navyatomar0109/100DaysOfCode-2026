#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* segregateEvenOdd(struct ListNode* head) {
    struct ListNode evenDummy, oddDummy;
    evenDummy.next = NULL;
    oddDummy.next = NULL;
    
    struct ListNode* evenTail = &evenDummy;
    struct ListNode* oddTail = &oddDummy;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        if (curr->val % 2 == 0) {
            evenTail->next = curr;
            evenTail = evenTail->next;
        } else {
            oddTail->next = curr;
            oddTail = oddTail->next;
        }
        curr = curr->next;
    }
    
    // Connect even list tail to odd list head
    evenTail->next = oddDummy.next;
    // Terminate the odd list tail to prevent cycles
    oddTail->next = NULL;
    
    return evenDummy.next;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Example: 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6
    struct ListNode* head = createNode(17);
    head->next = createNode(15);
    head->next->next = createNode(8);
    head->next->next->next = createNode(9);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(6);

    printf("Original list: ");
    printList(head);

    head = segregateEvenOdd(head);

    printf("Modified list: ");
    printList(head);

    // Free memory
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
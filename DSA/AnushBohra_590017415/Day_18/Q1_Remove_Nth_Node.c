#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    
    // Move fast pointer so that there is a gap of n nodes between fast and slow
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move fast to the end, maintaining the gap
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Skip the nth node from the end
    struct ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    free(nodeToDelete);
    
    return dummy.next;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(",");
        head = head->next;
    }
    printf("]\n");
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int n = 2;
    head = removeNthFromEnd(head, n);

    printList(head);

    // Free remaining list memory
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return head;
    }

    struct ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            struct ListNode* duplicate = curr->next;
            curr->next = curr->next->next;
            free(duplicate);
        } else {
            curr = curr->next;
        }
    }

    return head;
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
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    head = deleteDuplicates(head);

    printList(head);

    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
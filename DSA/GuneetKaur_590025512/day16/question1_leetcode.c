#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *newHead = head->next;
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct ListNode *second = curr->next;
        struct ListNode *nextPair = second->next;

        second->next = curr;
        curr->next = nextPair;

        if (prev != NULL)
            prev->next = second;

        prev = curr;
        curr = nextPair;
    }

    return newHead;
}
struct ListNode* createNode(int data) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct ListNode **head, int data) {
    struct ListNode *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct ListNode *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *head = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    printf("Original List: ");
    printList(head);

    head = swapPairs(head);

    printf("After Swapping Pairs: ");
    printList(head);

    return 0;
}
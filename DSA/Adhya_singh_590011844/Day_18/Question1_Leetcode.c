#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int len = 1;
    struct Node *tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    k %= len;
    if (k == 0)
        return head;

    tail->next = head;

    int steps = len - k;
    struct Node *newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, k, value;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        struct Node *newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("Rotated Linked List: ");
    printList(head);

    return 0;
}
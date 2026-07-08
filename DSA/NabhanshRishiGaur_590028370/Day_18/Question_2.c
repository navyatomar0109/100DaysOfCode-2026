#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* removeNode(struct Node* head, int n, int* count) {
    if (head == NULL)
        return NULL;

    head->next = removeNode(head->next, n, count);

    (*count)++;

    if (*count == n) {
        struct Node* temp = head->next;
        free(head);
        return temp;
    }

    return head;
}

struct Node* removeNthFromEnd(struct Node* head, int n) {
    int count = 0;
    return removeNode(head, n, &count);
}

void printList(struct Node* head) {
    printf("[");

    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(",");
        head = head->next;
    }

    printf("]\n");
}

int main() {
    int n, x, k;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Enter n: ");
    scanf("%d", &k);

    head = removeNthFromEnd(head, k);

    printList(head);

    return 0;
}

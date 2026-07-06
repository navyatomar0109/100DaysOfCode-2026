#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteLast() {
    if (head == NULL)
        return;

    if (head == tail) {
        free(head);
        head = tail = NULL;
        return;
    }

    struct Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(x);
    }

    deleteLast();

    printf("Updated Doubly Linked List:\n");
    display();

    return 0;
}

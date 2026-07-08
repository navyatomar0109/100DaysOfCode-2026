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

struct Node* insertEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* middleNode(struct Node *head) {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;

    while (mid--) {
        temp = temp->next;
    }

    return temp;
}

int main() {
    int n, x;
    struct Node *head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    struct Node *mid = middleNode(head);

    if (mid != NULL)
        printf("Middle Node: %d\n", mid->data);

    return 0;
}

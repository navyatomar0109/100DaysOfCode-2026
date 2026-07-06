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

struct Node* rearrangeEvenOdd(struct Node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    struct Node *originalTail = tail;
    struct Node *prev = NULL;
    struct Node *curr = head;

    while (curr != originalTail->next) {
        if (curr->data % 2 != 0) {
            struct Node *nextNode = curr->next;

            if (prev == NULL)
                head = nextNode;
            else
                prev->next = nextNode;

            tail->next = curr;
            curr->next = NULL;
            tail = curr;

            curr = nextNode;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    head = rearrangeEvenOdd(head);

    printf("Rearranged Linked List:\n");
    printList(head);

    return 0;
}

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

struct Node* rotateRight(struct Node *head, int k) {

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int length = 1;
    struct Node *tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    k = k % length;

    if (k == 0)
        return head;
    tail->next = head;
    int steps = length - k;
    struct Node *newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < n; i++) {

        struct Node *newNode = createNode(arr[i]);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k = 2;

    printf("Original List: ");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated List: ");
    printList(head);

    return 0;
}
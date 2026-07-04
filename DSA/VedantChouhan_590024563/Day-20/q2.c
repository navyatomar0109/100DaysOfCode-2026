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

struct Node* rearrangeEvenOdd(struct Node *head) {

    if (head == NULL)
        return NULL;

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;

    struct Node *current = head;

    while (current != NULL) {

        struct Node *nextNode = current->next;
        current->next = NULL;

        if (current->data % 2 == 0) {

            if (evenHead == NULL) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }

        } else {

            if (oddHead == NULL) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }

        current = nextNode;
    }

    if (evenHead == NULL)
        return oddHead;

    evenTail->next = oddHead;

    return evenHead;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    int arr[] = {17, 15, 8, 12, 10, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Create linked list using loop
    for (int i = 0; i < n; i++) {

        struct Node *newNode = createNode(arr[i]);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original List: ");
    printList(head);

    head = rearrangeEvenOdd(head);

    printf("Rearranged List: ");
    printList(head);

    return 0;
}
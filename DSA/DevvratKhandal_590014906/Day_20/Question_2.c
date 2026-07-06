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

void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct Node* segregateEvenOdd(struct Node *head) {

    if (head == NULL)
        return NULL;

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;

    struct Node *current = head;

    while (current != NULL) {

        if (current->data % 2 == 0) {

            if (evenHead == NULL) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }

        } else {

            if (oddHead == NULL) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }

        current = current->next;
    }

    if (evenHead == NULL) {
        oddTail->next = NULL;
        return oddHead;
    }

    evenTail->next = oddHead;

    if (oddTail != NULL)
        oddTail->next = NULL;

    return evenHead;
}

void printList(struct Node *head) {

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    struct Node *head = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    head = segregateEvenOdd(head);

    printf("Rearranged List: ");
    printList(head);

    return 0;
}
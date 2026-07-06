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

struct Node* divide(struct Node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;
    struct Node *curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            if (evenHead == NULL)
                evenHead = evenTail = curr;
            else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            if (oddHead == NULL)
                oddHead = oddTail = curr;
            else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
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
    printf("\n");
}

int main() {
    int n, value;
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

    head = divide(head);

    printf("Rearranged List: ");
    printList(head);

    return 0;
}
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

struct Node* removeElements(struct Node *head, int val) {

    struct Node dummy;
    dummy.next = head;

    struct Node *current = &dummy;

    while (current->next != NULL) {

        if (current->next->data == val) {
            struct Node *temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return dummy.next;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Create linked list using loop
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

    int val = 6;

    printf("Original List: ");
    printList(head);

    head = removeElements(head, val);

    printf("Updated List: ");
    printList(head);

    return 0;
}
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

struct Node* removeDuplicates(struct Node *head) {

    struct Node *current = head;

    while (current != NULL && current->next != NULL) {

        if (current->data == current->next->data) {

            struct Node *temp = current->next;
            current->next = temp->next;
            free(temp);

        } else {
            current = current->next;
        }
    }

    return head;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    int arr[] = {1, 1, 2, 3, 3, 4, 4, 5};
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

    printf("Original List: ");
    printList(head);

    head = removeDuplicates(head);

    printf("After Removing Duplicates: ");
    printList(head);

    return 0;
}
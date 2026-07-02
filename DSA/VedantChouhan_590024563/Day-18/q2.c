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

struct Node* removeNthFromEnd(struct Node *head, int n) {

    struct Node dummy;
    dummy.next = head;

    struct Node *fast = &dummy;
    struct Node *slow = &dummy;

    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct Node *temp = slow->next;
    slow->next = temp->next;
    free(temp);

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

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < size; i++) {

        struct Node *newNode = createNode(arr[i]);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int n = 2;

    printf("Original List: ");
    printList(head);

    head = removeNthFromEnd(head, n);

    printf("Updated List: ");
    printList(head);

    return 0;
}
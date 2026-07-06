#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool hasCycle(struct Node *head) {

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {

    int arr[] = {3, 2, 0, -4};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *nodes[100];

    // Create linked list
    for (int i = 0; i < n; i++) {

        struct Node *newNode = createNode(arr[i]);
        nodes[i] = newNode;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // pos = 1 (last node points to node with value 2)
    int pos = 1;

    if (pos != -1)
        tail->next = nodes[pos];

    if (hasCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
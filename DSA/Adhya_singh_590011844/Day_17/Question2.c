#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool hasCycle(struct Node* head) {
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
    int n, pos;
    struct Node *head = NULL, *tail = NULL;
    struct Node *nodes[100];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        nodes[i] = createNode(value);

        if (head == NULL) {
            head = tail = nodes[i];
        } else {
            tail->next = nodes[i];
            tail = nodes[i];
        }
    }

    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    if (pos >= 0 && pos < n)
        tail->next = nodes[pos];

    if (hasCycle(head))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}
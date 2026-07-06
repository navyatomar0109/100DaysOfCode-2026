#include <stdio.h>
#include <stdlib.h>

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

struct Node* removeNthFromEnd(struct Node* head, int n) {
    struct Node dummy;
    dummy.next = head;

    struct Node *fast = &dummy;
    struct Node *slow = &dummy;

    for (int i = 0; i <= n; i++)
        fast = fast->next;

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct Node *temp = slow->next;
    slow->next = temp->next;
    free(temp);

    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, value, k;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter n (node from end to remove): ");
    scanf("%d", &k);

    head = removeNthFromEnd(head, k);

    printf("Updated Linked List: ");
    printList(head);

    return 0;
}
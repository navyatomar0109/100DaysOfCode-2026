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

struct Node* removeElements(struct Node *head, int val) {

    while (head != NULL && head->data == val) {
        head = head->next;
    }

    struct Node *current = head;

    while (current != NULL && current->next != NULL) {

        if (current->next->data == val)
            current->next = current->next->next;
        else
            current = current->next;
    }

    return head;
}

void printList(struct Node *head) {

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    struct Node *head = NULL;
    int n, val, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    printf("Enter value to remove: ");
    scanf("%d", &val);

    head = removeElements(head, val);

    printf("Updated List: ");
    printList(head);

    return 0;
}
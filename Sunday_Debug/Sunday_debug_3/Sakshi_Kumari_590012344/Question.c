
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void removeLoop(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return;

    slow = head;

    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;

        fast->next = NULL;
        return;
    }

    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

void deleteNode(struct Node **head, int key) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
int findMiddle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main() {
    struct Node *head = NULL
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    struct Node *temp = head;
    struct Node *loopNode = NULL;
    while (temp->next != NULL) {
        if (temp->data == 3)
            loopNode = temp;
        temp = temp->next;
    }
    temp->next = loopNode;
    removeLoop(head);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    printf("Backup Leader: %d\n", findMiddle(head));
    return 0;
}

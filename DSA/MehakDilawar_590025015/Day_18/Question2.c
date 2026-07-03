//Remove the nth node from the end of a singly linked list and print the updated linked list.
//Input:head = [1,2,3,4,5], n = 2. Output:[1,2,3,5]
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

struct Node* removeNthFromEnd(struct Node* head, int n) {
    struct Node dummy;
    dummy.next = head;
    struct Node *first = &dummy, *second = &dummy;
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    struct Node *temp = second->next;
    second->next = temp->next;
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
    int size, value, n;
    printf("Enter number of nodes: ");
    scanf("%d", &size);
    struct Node *head = NULL, *tail = NULL;
    printf("Enter node values:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &value);
        struct Node *newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("Enter n: ");
    scanf("%d", &n);
    head = removeNthFromEnd(head, n);
    printf("Updated Linked List: ");
    printList(head);

return 0;
}
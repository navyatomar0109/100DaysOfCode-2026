// Problem 2 
// Middle of the Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* middleNode(struct Node *head, int n) {
    struct Node *temp = head;
    for(int i = 0; i < n / 2; i++) {
        temp = temp->next;
    }
    return temp;
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *temp = NULL;

    printf("Enter the elements: ");

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node *newNode = createNode(value);
        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    struct Node *middle = middleNode(head, n);
    printf("Middle node: %d", middle->data);
    return 0;
}
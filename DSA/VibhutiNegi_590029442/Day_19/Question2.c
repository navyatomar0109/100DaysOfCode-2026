#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct node* middleNode(struct node* head) {
    struct node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < count / 2; i++) {
        temp = temp->next;
    }
    return temp;
}
int main() {
    int n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n == 0) {
        printf("Linked list is empty.\n");
        return 0;
    }
    struct node *head = NULL, *tail = NULL;
    printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct node *newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    struct node *middle = middleNode(head);
    printf("Middle node is: %d\n", middle->data);
    return 0;
}
// Problem 2 
// Segregate Even and Odd Nodes in a Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

struct Node *segregateEvenOdd(struct Node *head) {
    if (head == NULL || head->next == NULL){
        return head;
    }

    struct Node *evenStart = NULL;
    struct Node *evenEnd = NULL;
    struct Node *oddStart = NULL;
    struct Node *oddEnd = NULL;
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            if (evenStart == NULL) {
                evenStart = temp;
                evenEnd = temp;
            }
            else {
                evenEnd->next = temp;
                evenEnd = temp;
            }
        }
        else {
            if (oddStart == NULL) {
                oddStart = temp;
                oddEnd = temp;
            }
            else {
                oddEnd->next = temp;
                oddEnd = temp;
            }
        }
        temp = temp->next;
    }

    if (evenStart == NULL) {
        oddEnd->next = NULL;
        return oddStart;
    }
    if (oddStart == NULL) {
        evenEnd->next = NULL;
        return evenStart;
    }

    evenEnd->next = oddStart;
    oddEnd->next = NULL;

    return evenStart;
}

int main() {
    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    head = segregateEvenOdd(head);
    printf("Updated Linked List: ");
    display(head);
    return 0;
}
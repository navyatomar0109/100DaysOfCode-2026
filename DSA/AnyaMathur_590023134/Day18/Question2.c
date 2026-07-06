/* Problem 2 
Remove Nth Node From End of Linked List */

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
    int length = 0;
    struct Node *temp = head;

    while(temp != NULL) {
        length++;
        temp = temp->next;
    }

    if(length == n) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    temp = head;

    for(int i = 1; i < length - n; i++) {
        temp = temp->next;
    }

    struct Node *NodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(NodeToDelete);

    return head;
}

void display(struct Node *head) {
    if(head == NULL){
        printf("NULL");
        return;
    }
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, value, remove;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *temp = NULL;

    printf("Enter elements of the linked list: ");

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        if(head == NULL) {
            head = createNode(value);
            temp = head;
        }
        else {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }

    printf("Enter n: ");
    scanf("%d", &remove);

    head = removeNthFromEnd(head, remove);

    printf("Updated Linked List: ");
    display(head);

    return 0;
}
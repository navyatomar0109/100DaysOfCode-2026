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

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* middleNode(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    int n, x;
    printf("Enter the number of elements you want to add in the linked list: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("The linked list is empty.\n");
        return 0;
    }

    printf("Enter %d values separated by spaces: ", n);
    scanf("%d", &x);
    struct Node *head = createNode(x);
    struct Node *tail = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        tail->next = createNode(x);
        tail = tail->next;
    }

    printf("\nLinked List: ");
    printList(head);

    struct Node *mid = middleNode(head);
    printf("Middle Node: %d\n", mid->data);

    return 0;
}

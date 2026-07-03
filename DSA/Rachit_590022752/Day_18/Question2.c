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
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (n == count) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    temp = head;

    for (int i = 1; i < count - n; i++) {
        temp = temp->next;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int size, n, value;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &size);

    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &value);

        struct Node *newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter n: ");
    scanf("%d", &n);

    head = removeNthFromEnd(head, n);

    printf("Updated List: ");
    printList(head);

    return 0;
}

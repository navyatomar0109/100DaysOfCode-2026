#include <stdio.h>
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
struct Node* removeNthFromEnd(struct Node* head, int n) {                        //       DELETE FROM NTH NODE FROM END
    struct Node dummy;
    dummy.next = head;
    struct Node *fast = &dummy;
    struct Node *slow = &dummy;

    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

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
}
int main() {
    int size, n;
    scanf("%d", &size);
    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < size; i++) {
        int x;
        scanf("%d", &x);

        struct Node *newNode = createNode(x);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &n);
    head = removeNthFromEnd(head, n);
    printList(head);
    return 0;
}





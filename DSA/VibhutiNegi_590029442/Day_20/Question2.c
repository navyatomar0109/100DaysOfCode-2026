#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* next;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
struct Node* rearrangeEvenOdd(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* evenHead = NULL;
    struct Node* evenTail = NULL;
    struct Node* oddHead = NULL;
    struct Node* oddTail = NULL;
    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->val % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = curr;
                evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = curr;
                oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }
    if (oddHead == NULL) {
        evenTail->next = NULL;
        return evenHead;
    }
    if (evenHead == NULL) {
        oddTail->next = NULL;
        return oddHead;
    }
    evenTail->next = oddHead;
    oddTail->next = NULL;
    return evenHead;
}
struct Node* takeInput() {
    int n, val;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = takeInput();
    head = rearrangeEvenOdd(head);
    printList(head);
    return 0;
}
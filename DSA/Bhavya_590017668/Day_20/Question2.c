#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* segregateEvenOdd(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *evenStart = NULL, *evenEnd = NULL;
    struct Node *oddStart = NULL, *oddEnd = NULL;
    struct Node *curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            if (evenStart == NULL) {
                evenStart = curr;
                evenEnd = curr;
            } else {
                evenEnd->next = curr;
                evenEnd = curr;
            }
        } else {
            if (oddStart == NULL) {
                oddStart = curr;
                oddEnd = curr;
            } else {
                oddEnd->next = curr;
                oddEnd = curr;
            }
        }
        curr = curr->next;
    }

    if (evenStart == NULL)
        return oddStart;

    if (oddStart == NULL)
        return evenStart;

    evenEnd->next = oddStart;
    oddEnd->next = NULL;

    return evenStart;
}
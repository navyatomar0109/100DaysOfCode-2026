#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode *temp = slow->next;
    slow->next = temp->next;
    free(temp);
    return dummy.next;
}
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
int main() {
    int size, n;
    printf("Enter number of nodes: ");
    scanf("%d", &size);
    if (size == 0) {
        return 0;
    }
    struct ListNode *head = NULL, *tail = NULL;
    printf("Enter node values: ");
    for (int i = 0; i < size; i++) {
        int x;
        scanf("%d", &x);
        struct ListNode *newNode = createNode(x);
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
    printf("Updated Linked List: ");
    printList(head);
    return 0;
}
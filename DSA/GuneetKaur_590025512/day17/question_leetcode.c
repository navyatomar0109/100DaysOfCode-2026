#include<Stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        printf("true\n");
        return;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    //pehle middle find krenge 
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *second = reverse(slow->next);

    //fir do alag lists ko comapre krenge
    struct ListNode *first = head;
    struct ListNode *temp = second;

    while (temp != NULL) {
        if (first->val != temp->val) {
            slow->next = reverse(second); 
            printf("false\n");
            return;
        }
        first = first->next;
        temp = temp->next;
    }
    slow->next = reverse(second);

    printf("true\n");
}
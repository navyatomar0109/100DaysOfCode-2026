#include<stdio.h>
#include<stdlib.h>
//Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode temp;
    temp.next = head;
    struct ListNode *prev = &temp;

    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode *first = prev->next;
        struct ListNode *second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }

    return temp.next;
}
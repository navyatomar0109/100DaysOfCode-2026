/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length and last node
    int length = 1;
    struct ListNode *tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Reduce unnecessary rotations
    k = k % length;

    if (k == 0)
        return head;

    // Make the list circular
    tail->next = head;

    // Find new tail
    int steps = length - k - 1;
    struct ListNode *newTail = head;

    while (steps--) {
        newTail = newTail->next;
    }

    // New head
    struct ListNode *newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}

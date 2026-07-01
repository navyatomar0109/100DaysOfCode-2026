/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr != NULL) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *second = reverse(slow->next);
    struct ListNode *first = head;
    struct ListNode *temp = second;
    while (temp != NULL) {
        if (first->val != temp->val)
            return false;
        first = first->next;
        temp = temp->next;
    }
    return true;
}